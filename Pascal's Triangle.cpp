#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> > generate(int numRows) {
      vector<vector<int> > result;

      for(int i=0 ; i<numRows; i++){
      	    vector<int> temp;
      		if(i==0) {
      			temp.push_back(1);
      			result.push_back(temp);
      			continue;
      		}

      		for(int j=0 ; j<=i ; j++){
      			if(j==0) temp.push_back(result.at(i-1)[j]);
      			else if(j==i) temp.push_back(result.at(i-1)[j-1]);
      			else{
      				temp.push_back(result.at(i-1)[j-1]+result.at(i-1)[j]);
      			}
      		}
      		result.push_back(temp);
      }
      return result; 
}

int main(int argc, char const *argv[])
{
	/* code */
	vector<vector<int> > result = generate(5);
	for(int i=0 ;i<result.size(); i++){
		for(int j=0; j<result.at(i).size(); j++){
			cout<<result.at(i)[j];
		}
		cout<<endl;
	}
	return 0;
}