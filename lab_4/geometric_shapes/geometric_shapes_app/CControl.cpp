#include "CControl.h"

using namespace std;

CControl::CControl(istream& input, ostream& output)
	: m_input(input)
	, m_output(output)
	, m_actionMap(
		  { { "line", [this](istream& strm) {
				 GetInputStrVector(strm);

				 if (!CheckLineArgs())
				 {
					 m_inputStrVector.clear();
					 m_output << "Invalid line shape args\n";
					 return false;
				 }
				 
				 AddLine();

				 return true;
			 } },

			  { "triangle", [this](istream& strm) {
				   GetInputStrVector(strm);
				   if (!CheckTriangleArgs())
				   {
					   m_inputStrVector.clear();
					   m_output << "Invalid triangle shape args\n";
					   return false;
				   }

				   AddTriangle();

				   return true;
			   } },

			  { "rectangle", [this](istream& strm) {
				   GetInputStrVector(strm);
				   if (!CheckRectangleArgs())
				   {
					   m_inputStrVector.clear();
					   m_output << "Invalid rectangle shape args\n";
					   return false;
				   }

				   AddRectangle();

				   return true;
			   } },

			  { "circle", [this](istream& strm) {
				   GetInputStrVector(strm);
				   if (!CheckCircleArgs())
				   {
					   m_inputStrVector.clear();
					   m_output << "Invalid circle shape args\n";
					   return false;
				   }

				   AddCircle();
				   
				   return true;
			   } },

			  { "info", [this](istream& strm) {
				   PrintInfo();
				   return true;
			   } },
		  })
{
}

bool CControl::GetInputStrVector(istream& strm)
{
	istream_iterator<string> doubleStrmBegin(strm);
	istream_iterator<string> doubleStrmEnd;
	copy(doubleStrmBegin, doubleStrmEnd, inserter(m_inputStrVector, m_inputStrVector.begin()));
	return true;
}

bool CControl::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	if (!m_input.eof())
	{
		m_output << "\nUnknown shape / command\n";
	}
	return false;
}
