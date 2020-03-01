/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 *
 * https://leetcode.com/problems/push-dominoes/description/
 *
 * algorithms
 * Medium (44.76%)
 * Likes:    335
 * Dislikes: 37
 * Total Accepted:    13.5K
 * Total Submissions: 30.1K
 * Testcase Example:  '".L.R...LR..L.."'
 *
 * There are N dominoes in a line, and we place each domino vertically
 * upright.
 * 
 * In the beginning, we simultaneously push some of the dominoes either to the
 * left or to the right.
 * 
 * 
 * 
 * After each second, each domino that is falling to the left pushes the
 * adjacent domino on the left.
 * 
 * Similarly, the dominoes falling to the right push their adjacent dominoes
 * standing on the right.
 * 
 * When a vertical domino has dominoes falling on it from both sides, it stays
 * still due to the balance of the forces.
 * 
 * For the purposes of this question, we will consider that a falling domino
 * expends no additional force to a falling or already fallen domino.
 * 
 * Given a string "S" representing the initial state. S[i] = 'L', if the i-th
 * domino has been pushed to the left; S[i] = 'R', if the i-th domino has been
 * pushed to the right; S[i] = '.', if the i-th domino has not been pushed.
 * 
 * Return a string representing the final state. 
 * 
 * Example 1:
 * 
 * 
 * Input: ".L.R...LR..L.."
 * Output: "LL.RR.LLRRLL.."
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "RR.L"
 * Output: "RR.L"
 * Explanation: The first domino expends no additional force on the second
 * domino.
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= N <= 10^5
 * String dominoes contains only 'L', 'R' and '.'
 * 
 * 
 */
class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<int> left(dominoes.length(),-1), right(dominoes.length(),-1);
        string ans;
        for(int i=0; i<dominoes.length(); i++){
            if(dominoes[i]=='.'&&i>0){
                right[i] = right[i-1];
            }else if (dominoes[i]=='R')
            {
                right[i] =  i;
            }
        }
        for (int i=dominoes.length()-1; i>=0; i--){
            if(dominoes[i]=='.'&&i<(dominoes.length()-1)){
                left[i] = left[i+1];
            }else if(dominoes[i]=='L'){
                left[i] = i;
            }
        }

        for (int i=0; i<dominoes.length(); i++){
            if((left[i]==-1&&right[i]==-1)||(left[i]!=-1&&right[i]!=-1&&abs(i-left[i])==abs(i-right[i])))
                ans.push_back('.');
            else if(left[i]==-1)
                ans.push_back('R');
            else if(right[i]==-1)
                ans.push_back('L');
            else if(abs(i-right[i])<abs(i-left[i]))
                ans.push_back('R');
            else 
                ans.push_back('L');
        }
        return ans;
    }
 };

