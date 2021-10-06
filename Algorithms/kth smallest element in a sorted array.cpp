//378. Kth Smallest Element in a Sorted Matrix(leetcode)





/*Given an n x n matrix where each of the rows and columns are sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

 */





class Solution {
public:
    int count(vector<vector<int>>& a, int mid)
    {
        int n=a.size();
        int i=n-1; //bottomost row
        int j=0; //first column
        int ans=0;
        //we will start from bottom rows left most element 
        while(i>=0 && j<n)
        {
            if(a[i][j]>mid) i--; //if element i greater than mid ,then we will go upwards
            
            else
            {
                ans+=i+1; 
                j++;
            }
        }
        return ans; //count of elements less than and equal to mid
    }
    
    
    
    
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
       //one of the simple is binary search over all diffreent elemant
        int n=matrix.size();
        int left_row=matrix[0][0];
        int bottom_right =matrix[n-1][n-1];
        int ans;ans=0;
        while(left_row<=bottom_right)  
        {
            int mid=((left_row)+(bottom_right))/2;
            if(count(matrix,mid)<k)
            {
               left_row=mid+1;
            }
            else
            {
                ans=mid;
               bottom_right=mid-1;
            }
            
        }
        return left_row;
        
    }
};
