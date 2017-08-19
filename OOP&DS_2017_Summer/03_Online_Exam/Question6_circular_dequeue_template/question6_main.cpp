#include <iostream>
#include <string>
#include "CirDequeTemplate.h"
int main()
{
	CirDequeTemplate<int> queue;
	string cmd;
	int val;
	while(cin>>cmd)
	{
		if(cmd == "popf")
			queue.pop_front();
		else if(cmd == "popb")
			queue.pop_back();
		else if(cmd == "pushb")
		{
			cin>>val;
			queue.push_back(val);
		}
		else if(cmd == "pushf")
		{
			cin>>val;
			queue.push_front(val);
		}
		else if(cmd == "shiftl")
		{
			queue.push_back(queue.pop_front());
		}
		else if(cmd == "shiftr")
		{
			queue.push_front(queue.pop_back());
		}
		else if(cmd == "dump")
		{
			cout<<queue<<endl;
		}
		
	}
	
	return 0;
}