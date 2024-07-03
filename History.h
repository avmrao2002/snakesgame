#if !defined(HISTORY_H)
#define HISTORY_H

class CHistory
{
private:	 
	 int i[MAXHISTORY];
	 int j[MAXHISTORY];
	 int m_iHistory; 
	 
public:
	CHistory();
	void SetHistory(int i,int j);
	void GetHistory(int &i,int &j);	
	void GetHistory(int index,int &outi,int &outj);
	void BackHistory();
	void ClearHistory();
	int GetHistoryCount();
};
#endif