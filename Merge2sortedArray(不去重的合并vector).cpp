void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /** 注意： 题目并没有要求去重复的元素！！！所以合并后的长度一定是m＋n
         * //使用空间O（n）的话简单，用个新的vector做，最后swap下，但是尽量空间别O（n）,或者先把nums2copy到nums1，然后排序，这样空间也是一样
         * 下面是我自己做的时候的想法，naive，还把nums1后移了怕污染。。
        int length = 0;
        int i=0,j=0;
       
        //这个要求再nums1里面做的，会出现nums1污染的问题
        while((i<m)&&(j<n)){
            if(nums1[i]<=nums2[j]){
                while((nums1[i]<=nums2[j])&&(i<m)){
                     nums1[length++] = nums1[i++];
                }
            }
            else{ //if(nums1[i]>nums2[j])
                   int backStep = 1; //为了防止数据污染，需要把nums1的数据往后挪即为，相当于插入
                   //while((nums1[i]>nums2[j])&&(j<n))
                while((nums1[i]>nums2[j])&&(j<n)){
                    
                    for(int back=m+1-1; back>=i+1; back--)
                        nums1[back] = nums1[back-1];
                    
                    nums1[length++] = nums2[j++];
                    i++;m++ ;//因为nums1整体往后移了一位，因此i,m也要增加
                }
            }
        }
        if(i>=m){ //说明是nums1用完了
            for(int k=j; k<n; k++)
                nums1[length++] = nums2[k];
        }else{ //nums2用完了
            for(int k=i; k<m; k++)
                nums1[length++] = nums1[k];
        }
    }
    */
    //看了discuss里面的做法，因为确定长度是m＋n，因此从nums1最后末尾开始赋值，这样也不会污染nums1的数据
    int i = m-1, j = n-1, tot = m+n-1; //caution -1
    while((i>=0)&&(j>=0)){
        if(nums1[i]>nums2[j])
            nums1[tot--] = nums1[i--];
        else 
            nums1[tot--] = nums2[j--];
    }
    //最后如果j先结束，那么下面这个也不会执行，因为nums1的元素按顺序在里面了，不必动；否则就把剩下的j填充nums1
    while(j>=0)
        nums1[tot--] = nums2[j--];
    }