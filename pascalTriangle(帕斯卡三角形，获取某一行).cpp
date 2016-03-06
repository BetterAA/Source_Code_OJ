#include<iostream>
#include< 

 vector<int> getRow(int rowIndex) {
        //方法1 ： 用队列的出队入队的方式模拟下一行的计算过程,这样的话就得用到queue而不是vector，但返回值是vector的。。
       //所以可以不需要出队入队，直接in place 原值上修改，首位1不动，重新计算下一位的值然后覆盖，最后pushback 1
        vector<int> row;
         //防止上一个数污染了之后影响下一个,这里用了两个遍历轮换保存，费了很多时间！
        for(int i=0; i<=rowIndex; i++){
            //get every row, first one donot modify
            int lastValue = 1,nowValue;
            for(int j=1 ; j<i; j++){
                nowValue = row[j];
                row[j] = lastValue+row[j]; //防止上一个数污染了之后影响下一个
                swap(lastValue,nowValue);
            }
            row.push_back(1);
        }
        return row;
    }