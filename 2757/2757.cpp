#include <iostream>
#include <vector>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int nNum;
	int nElement;
	vector<int> nVector;
	cin >> nNum;
	/*
	if (nNum == 1)
	{
		cout<< 1<<endl;
		return 0;
	}*/
	for (int i = 0; i < nNum; i++)
	{
		cin >> nElement;
		nVector.push_back(nElement);
	}
	/*
	for (vector<int>::iterator npIter = nVector.begin(); npIter != nVector.end(); npIter++)
		cout << *npIter;
	cout << endl;
	*/
	vector<int> nVecData(nNum,1);
	vector<int> nVecIdx(nNum,0);
	int nMax = 1;
	int nIdx = 0;
	for (int i = 0; i < nNum; i++)
	{
		int nTemp = 0;
		nIdx = 0; 
		int j;
		for (j = 0; j < i; j++)
		{
			if (nVector[i] > nVector[j])
				if (nTemp < nVecData[j])
					{
						nTemp = nVecData[j];
						nIdx = j;
					}
		}
		nVecData[i] = nTemp + 1;
		cout << nIdx <<' ';
		// nVecIdx.push_back(nIdx);
		nVecIdx[i]=nIdx;
		// �����push_back��õ�ȫ0����Ϊpush_back������,�����ظ����ã��������new�����Ķ���һ������������ظ�����һ��ֵ�� 
	}
	cout<< endl;
	nIdx = 0;
	for (int i = 0; i < nNum; i++)
	{
		if (nVecData[i] > nMax)
		{
			nMax = nVecData[i];
			nIdx = i;
		}
	}
	for (int j = 0; j < nNum; j++)
		cout<<nVecIdx[j];
	cout<<endl;
	for (int j = 0; j < nMax; j++)
	{
		int nTemp;
		int T;
		nTemp = nVector[nIdx];
		cout<< nTemp<<' '<<nIdx<<' '<<endl;
		T = nVecIdx[nIdx];
		nIdx = T;
		
	}
	cout<< endl;
	cout << nMax;
	return 0;
}
