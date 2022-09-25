#include <msclr/marshal_cppstd.h>
#include <msclr/marshal.h>
#include <codecvt>
#include <string>

#pragma once
namespace QzCPP
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	std::string fromSystemstringToString(System::String^ text)
	{
		return converter.to_bytes(msclr::interop::marshal_as<std::wstring>(text));
	}
	System::String^ fromStringToSystemstring(std::string text)
	{
		return gcnew System::String(converter.from_bytes(text).c_str());
	}
}