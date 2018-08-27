/**
* @filename xml2json.h
* @brief convert xml to json string
*        from http://github.com/cheedoong/xml2json
*        Copyright (C) 2013 Alan Zhuang (Cheedoong)	Tencent, Inc.
*/

#ifndef _THEFOX_BASE_XML2JSON_H_
#define _THEFOX_BASE_XML2JSON_H_

#include <map>
#include <string>

#include <thirdparty/rapidxml/rapidxml.hpp>
#include <thirdparty/rapidxml/rapidxml_utils.hpp>
#include <thirdparty/rapidxml/rapidxml_print.hpp>

#include <thirdparty/rapidjson/document.h>
#include <thirdparty/rapidjson/writer.h>
#include <thirdparty/rapidjson/prettywriter.h>
#include <thirdparty/rapidjson/encodedstream.h>
#include <thirdparty/rapidjson/stringbuffer.h>

#include <string>

namespace thefox {

void to_array_form_node(rapidxml::xml_node<> *xmlnode_chd, rapidjson::Value &jsvalue, rapidjson::Value &jsvalue_chd, rapidjson::Document::AllocatorType& allocator)
{
	rapidjson::Value jsvalue_target; // target to do some operation

	jsvalue_target = jsvalue.FindMember(xmlnode_chd->name())->value;
	if (jsvalue_target.IsArray()) {
		jsvalue_target.PushBack(jsvalue_chd, allocator);
		jsvalue.RemoveMember(xmlnode_chd->name());
		jsvalue.AddMember(xmlnode_chd->name(), jsvalue_target, allocator);
	} else {
		rapidjson::Value jsvalue_array;
		//jsvalue_array = jsvalue_target;
		jsvalue_array.SetArray();
		jsvalue_array.PushBack(jsvalue_target, allocator);
		jsvalue_array.PushBack(jsvalue_chd, allocator);
		jsvalue.RemoveMember(xmlnode_chd->name());
		jsvalue.AddMember(xmlnode_chd->name(), jsvalue_array, allocator);
	}
}

void to_array_form(const char *name, rapidjson::Value &jsvalue, rapidjson::Value &jsvalue_chd, rapidjson::Document::AllocatorType& allocator)
{
	rapidjson::Value jsvalue_target; // target to do some operation

	jsvalue_target = jsvalue.FindMember(name)->value;
	if (jsvalue_target.IsArray()) {
		jsvalue_target.PushBack(jsvalue_chd, allocator);
		jsvalue.RemoveMember(name);
		jsvalue.AddMember(name, jsvalue_target, allocator);
	} else {
		rapidjson::Value jsvalue_array;
		//jsvalue_array = jsvalue_target;
		jsvalue_array.SetArray();
		jsvalue_array.PushBack(jsvalue_target, allocator);
		jsvalue_array.PushBack(jsvalue_chd, allocator);
		jsvalue.RemoveMember(name);
		jsvalue.AddMember(name, jsvalue_array, allocator);
	}
}

void add_attributes(rapidxml::xml_node<> *xmlnode, rapidjson::Value &jsvalue, rapidjson::Document::AllocatorType& allocator)
{
	rapidjson::Value jsvalue_attr;

	rapidxml::xml_attribute<> *myattr;
	for (myattr = xmlnode->first_attribute(); myattr; myattr = myattr->next_attribute()) {
		rapidjson::Value jv;
		jv.SetString((std::string("@") + myattr->name()).c_str(), allocator);
		jsvalue.AddMember(jv.GetString(), myattr->value(), allocator);
	}
}

void traverse_node(rapidxml::xml_node<> *xmlnode, rapidjson::Value &jsvalue, rapidjson::Document::AllocatorType& allocator)
{
	//cout << "this: " << xmlnode->type() << " name: " << xmlnode->name() << " value: " << xmlnode->value() << endl;
	rapidjson::Value jsvalue_chd;

	jsvalue.SetObject();
	jsvalue_chd.SetObject();
	rapidxml::xml_node<> *xmlnode_chd;

	// classified discussion:
	if ((xmlnode->type() == rapidxml::node_data || xmlnode->type() == rapidxml::node_cdata) && xmlnode->value()) {
		// case: pure_text
		jsvalue.SetString(xmlnode->value(), allocator); // then addmember("#text" , jsvalue, allocator)
	} else if (xmlnode->type() == rapidxml::node_element) {
		if (xmlnode->first_attribute()) {
			if (xmlnode->first_node() && xmlnode->first_node()->type() == rapidxml::node_data && count_children(xmlnode) == 1) {
				// case: <e attr="xxx">text</e>
				jsvalue.AddMember("#text", xmlnode->first_node()->value(), allocator);
				add_attributes(xmlnode, jsvalue, allocator);
				return;
			} else {
				// case: <e attr="xxx">...</e>
				add_attributes(xmlnode, jsvalue, allocator);
			}
		} else { if (!xmlnode->first_node()) {
				 // case: <e />
				 jsvalue.SetNull();
				 return;
			 } else if (xmlnode->first_node()->type() == rapidxml::node_data && count_children(xmlnode) == 1) {
				 // case: <e>text</e>
				 jsvalue.SetString(xmlnode->first_node()->value());
				 return;
			 }
		}
		if (xmlnode->first_node()) {
			// case: complex else...
			std::map<std::string, int> name_count;
			for (xmlnode_chd = xmlnode->first_node(); xmlnode_chd; xmlnode_chd = xmlnode_chd->next_sibling()) {
				std::string current_name;
				const char *name_ptr;
				if (xmlnode_chd->type() == rapidxml::node_data || xmlnode_chd->type() == rapidxml::node_cdata) {
					current_name = "#text";
					name_count[current_name]++;
					rapidjson::Value jv;
					jv.SetString("#text", allocator);
					name_ptr = jv.GetString();
				} else if (xmlnode_chd->type() == rapidxml::node_element) {
					current_name = xmlnode_chd->name();
					name_count[current_name]++;
					name_ptr = xmlnode_chd->name();
				}
				traverse_node(xmlnode_chd, jsvalue_chd, allocator);
				if (name_count[current_name] > 1)
					to_array_form(name_ptr, jsvalue, jsvalue_chd, allocator);
				else
					jsvalue.AddMember(name_ptr, jsvalue_chd, allocator);
			}
		}
	}
}


std::string xml2json(const std::string &xmlStr)
{
	rapidxml::xml_document<> doc;
	doc.parse<0>(const_cast<char *>(xmlStr.c_str()));

	rapidjson::Document document;
	document.SetObject();
	rapidjson::Document::AllocatorType& allocator = document.GetAllocator();

	rapidxml::xml_node<> *xmlnode_chd;

	for (xmlnode_chd = doc.first_node(); xmlnode_chd; xmlnode_chd = xmlnode_chd->next_sibling()) {
		//cout << xmlnode_chd->name() << endl;
		rapidjson::Value jsvalue_chd;
		jsvalue_chd.SetObject();
		traverse_node(xmlnode_chd, jsvalue_chd, allocator);
		document.AddMember(xmlnode_chd->name(), jsvalue_chd, allocator);
	}
	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	document.Accept(writer);
	return buffer.GetString();
}

} // namespace thefox

#endif //_THEFOX_BASE_XML2JSON_H_
