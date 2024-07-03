#include "stdafx.h"
#include "History.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CHistory::CHistory()
{
	m_iHistory = -1;
}
void CHistory::SetHistory(int ini,int inj)
	 
{
	m_iHistory++;
	i[m_iHistory]=ini;
	j[m_iHistory]=inj;
}

void CHistory::GetHistory(int &outi,int &outj)
{
	if(m_iHistory >=0)
	{
		outi=i[m_iHistory];
		outj=j[m_iHistory];
	}
}
void CHistory::GetHistory(int index,int &outi,int &outj)
{
	if(index >=0 && index <= m_iHistory)
	{
		outi=i[index];
		outj=j[index];
	}
}
void CHistory::BackHistory()
{
	if(m_iHistory >=0)
		m_iHistory--;
}
void CHistory::ClearHistory()
{
	m_iHistory = -1;
}
int CHistory::GetHistoryCount()
{
	return m_iHistory+1;
}