/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/

/**
*	@file		file_container.h
*	@author		lc
*	@date		2011/02/15	initial
*	@version	0.0.1.0
*	@brief
*/

#include "stdafx.h"
#include "file_container.h"

#include "read_ini.h"

namespace filesystem {

	BOOL file_container::erase_element(LPCTSTR sz_name_)
	{
		std::map<DWORD, tstring>::iterator iter;
		DWORD dw_id = get_tool()->crc32(sz_name_);

		iter = map_data.find(dw_id);
		if (iter == map_data.end())
			return FALSE;

		map_data.erase(iter);

		if (b_save)
		{
			iter = map_name.find(dw_id);
			map_name.erase(iter);
		}

		return TRUE;
	}

	BOOL file_container::erase_element(LPCTSTR sz_name_, LPCTSTR sz_section_)
	{
		tstring string = sz_name_;
		string.append(_T(" "));
		string.append(sz_section_);
		return erase_element(string.c_str());
	}


	//-----------------------------------------------------------------------------
	// 获取所有元素的名称标示
	//-----------------------------------------------------------------------------
	std::list<tstring>& file_container::get_element_name()
	{
		list_name.clear();
		std::map<DWORD, tstring>::iterator iter;

		for (iter = map_name.begin(); iter != map_name.end(); ++iter)
			list_name.push_back(iter->second);

		return list_name;
	}

	BOOL file_container::load(file_system* p_vfs, LPCTSTR sz_file_name_,
		LPCSTR sz_key_name_, std::list<tstring>* p_section_list_)
	{
		DWORD dw_time = timeGetTime();
		tstring str_file_name = sz_file_name_;
		if (str_file_name.find(_T(".xml")) != tstring::npos)
		{
			XmlDocument doc;
			if (!doc.LoadFile(p_vfs, sz_file_name_))
				return FALSE;

			XmlHandle doc_hangle(&doc);
			//XmlHandle ele_handle = doc_hangle.FirstChildElement("root").FirstChildElement();
			XmlHandle ele_handle = doc_hangle.FirstChildElement().FirstChildElement();
			XmlElement* p_element = ele_handle.Element();
			if (!p_element)
				return FALSE;

			TCHAR sz_section[HUGE_STRING];
			TCHAR sz_value[HUGE_STRING];
			TCHAR sz_name[HUGE_STRING];
			TCHAR sz_all_name[HUGE_STRING];
			m_xmlRow = 0;
			while (p_element)
			{
				LPCSTR sz_key_name = p_element->Attribute(sz_key_name_);
				if (!VALID_POINT(sz_key_name))
				{
					p_element = p_element->NextSiblingElement();
					continue;
				}

				get_tool()->unicode8_to_unicode(sz_key_name, sz_section);
				XmlAttribute* p_attribute = p_element->FirstAttribute();
				if (p_section_list_ && p_attribute)
					p_section_list_->push_back(sz_section);

				while (p_attribute)
				{
					if (p_attribute->ValueStr().empty())
					{
						p_attribute = p_attribute->Next();
						continue;
					}

					get_tool()->unicode8_to_unicode(p_attribute->Value(), sz_value);
					get_tool()->unicode8_to_unicode(p_attribute->Name(), sz_name);
					_tcscpy(sz_all_name, sz_name);
					_tcscat(sz_all_name, _T(" "));
					_tcscat(sz_all_name, sz_section);

					this->add_element(sz_value, sz_all_name);

					if (sz_name[0] == _T('v')
						&& sz_name[1] == _T('a')
						&& sz_name[2] == _T('l')
						&& sz_name[3] == _T('u')
						&& sz_name[4] == _T('e')
						&& sz_name[5] == 0)
						this->add_element(sz_value, sz_section);

					p_attribute = p_attribute->Next();
				}
				m_xmlRow++;
				p_element = p_element->NextSiblingElement();
			}
		}
		else if (str_file_name.find(_T(".inc")) != tstring::npos)
		{
			read_ini* p_obj = new read_ini;
			if (!VALID_POINT(p_obj))
				return FALSE;

			if (FALSE == p_obj->load_file(p_vfs, sz_file_name_, 1))
			{
				SAFE_DELETE(p_obj);
				return FALSE;
			}
			p_obj->lay_container(this);
			SAFE_DELETE(p_obj);
		}
		else if (str_file_name.find(_T(".ins")) != tstring::npos)
		{
			read_ini* p_obj = new read_ini;
			if (!VALID_POINT(p_obj))
				return FALSE;

			if (FALSE == p_obj->load_file(p_vfs, sz_file_name_, 0))
			{
				SAFE_DELETE(p_obj);
				return FALSE;
			}
			p_obj->lay_container(this);
			SAFE_DELETE(p_obj);
		}
		else
		{
			read_ini* p_obj = new read_ini;
			if (!VALID_POINT(p_obj))
				return FALSE;

			if (FALSE == p_obj->load_file(p_vfs, sz_file_name_))
			{
				SAFE_DELETE(p_obj);
				return FALSE;
			}
			p_obj->lay_container(this);
			SAFE_DELETE(p_obj);
		}

		return TRUE;
	}


	BOOL file_container::save(LPCTSTR sz_file_name_)
	{
		if (!b_save)
			return FALSE;

		tstring str_file_name = sz_file_name_;
		if (str_file_name.find(_T(".xml")) != tstring::npos)
		{
			XmlDocument doc;
			XmlDeclaration declaration("1.0", "UTF-8", "");
			doc.InsertEndChild(declaration);

			XmlElement ele_root("root");
			std::map<DWORD, tstring>::iterator iter;
			std::map<DWORD, tstring>::iterator iter_name;
			for (iter = map_data.begin(); iter != map_data.end(); ++iter)
			{
				iter_name = map_name.find(iter->first);
				std::string str_name = get_tool()->unicode_to_unicode8(iter_name->second.c_str());
				std::string str_value = get_tool()->unicode_to_unicode8(iter->second.c_str());

				if (str_name.find(" ") == std::string::npos)
					continue;

				std::string str_section;
				str_section.assign(str_name, str_name.find(" ") + 1, str_name.size() - str_name.find(" ") + 1);
				str_name.assign(str_name, 0, str_name.find(" "));

				BOOL b_find = FALSE;
				XmlElement* p_element = ele_root.FirstChildElement();
				while (p_element)
				{
					if (0 == strcmp(p_element->Attribute("name"), str_section.c_str()))
					{
						p_element->SetAttribute(str_name, str_value);
						b_find = TRUE;
						break;
					}

					p_element = p_element->NextSiblingElement();
				}

				if (!b_find)
				{
					XmlElement ele("item");
					ele.SetAttribute("name", str_section);
					ele.SetAttribute(str_name, str_value);
					ele_root.InsertEndChild(ele);
				}
			}

			doc.InsertEndChild(ele_root);
			doc.SaveFile(sz_file_name_);

		}
		else
		{
			return FALSE;
		}

		return TRUE;
	}

	BOOL file_container::set_element(LPCTSTR sz_value_, LPCTSTR sz_name_)
	{
		BOOL b_result = this->erase_element(sz_name_);
		this->add_element(sz_value_, sz_name_);
		return b_result;
	}

	BOOL file_container::set_element(DWORD dw_value_, LPCTSTR sz_name_)
	{
		BOOL b_result = this->erase_element(sz_name_);
		this->add_element(dw_value_, sz_name_);
		return b_result;
	}

	BOOL file_container::set_element(FLOAT f_value_, LPCTSTR sz_name_)
	{
		BOOL b_result = this->erase_element(sz_name_);
		this->add_element(f_value_, sz_name_);
		return b_result;
	}

} // namespace filesystem {
