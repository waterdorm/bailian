/*
#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char** argv) {
	int nNum;
	int nElement;
	vector<int> nVector;
	cin >> nNum;
	
	if (nNum == 1)
	{
		cout<< 1<<endl;
		return 0;
	}
	for (int i = 0; i < nNum; i++)
	{
		cin >> nElement;
		nVector.push_back(nElement);
	}
	
	for (vector<int>::iterator npIter = nVector.begin(); npIter != nVector.end(); npIter++)
		cout << *npIter;
	cout << endl;
	
	vector<vector<int> > nVecData(nNum,vector<int>(nNum,1));
	int nMax = 1;
	for (int i = 0; i < nNum; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nVector[i] > nVector[j])
				nVecData[i][j+1] = nVecData[j][j]+1;
			else
				nVecData[i][j+1] = nVecData[i][j];// ֻ����һ��Ƚϲ���һ�������ֵ��8 1 2 1 3 1 4 1 5���������Ľ�����Ǵ�ġ� 
			// ����Ľ�������ⲻӦ�������ڽӵĻ�ã�����������ϲ��ԣ����ܻᱻ��ϣ�������Ҫѡȡ֮ǰ�����ֵ������ȷ�⡣ 
			if (nVecData[i][j+1] > nMax)
				nMax = nVecData[i][j+1];
		}
		
	}
	
	for (int i = 0; i < nNum; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << nVecData[i][j];
		cout<< endl;
	}
	
	cout << nMax << endl;
	return 0;
}*/
