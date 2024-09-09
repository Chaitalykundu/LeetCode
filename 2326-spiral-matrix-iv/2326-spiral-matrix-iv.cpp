class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
         // Function to create a spiral matrix from a linked list
         ios::sync_with_stdio(false);
           // Disable synchronization of all standard C++ streams with their corresponding C streams
        cin.tie(nullptr);

         // Create a 2D array to store the matrix
       vector<vector<int>> s(m, vector<int>(n, -1));

        // Initialize variables to keep track of the current top, left, right, and bottom boundaries
        int tr=0,lr=m-1,lc=0,rc=n-1;
   // Traverse the linked list and fill the matrix in a spiral order
        while(head!=NULL){

             // Fill the top row from left to right
            for(int w=lc;w<=rc;w++){
                if(head==NULL)break;
                s[tr][w]=head->val;
                head=head->next;
            }
            tr++;
        // Fill the right column from top to bottom
            for( int w=tr;w<=lr;w++){
                if(head==NULL)break;
                s[w][rc]=head->val;
                head=head->next;
            }
            rc--;
       // Fill the bottom row from right to left
            for( int w=rc;w>=lc;w--){
                if(head==NULL)break;
                s[lr][w]=head->val;;
                head=head->next;
            }
            lr--;
        // Fill the left column from bottom to top
            for( int w=lr;w>=tr;w--){
                if(head==NULL)break;
                s[w][lc]=head->val;
                head=head->next;
            }
            lc++;
        }

       
            return s;
        
    }
};