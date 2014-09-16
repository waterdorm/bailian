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
				nVecData[i][j+1] = nVecData[i][j];// 只和上一层比较并不一定是最大值，8 1 2 1 3 1 4 1 5。这个输入的结果就是错的。 
			// 这里的解的子问题不应定是由邻接的获得，这个序列如上测试，可能会被打断，所以需要选取之前的最大值才是正确解。 
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
