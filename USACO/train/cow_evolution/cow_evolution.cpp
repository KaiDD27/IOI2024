// 二叉树可以确保使用 DFS 深度优先探索，每个节点只探索一次。
#include <fstream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int N;
int main()
{
    ifstream fin("evolution.in");
    ofstream fout("evolution.out");
    fin >> N;
    vector<set<string>> cows;
    set<string> all_char_set;
    for (int c = 0; c < N; c++)
    {
        int char_num;
        fin >> char_num;
        set<string> curr_cow;
        for (int i = 0; i < char_num; i++)
        {
            string characteristic;
            fin >> characteristic;
            curr_cow.insert(characteristic);
        }
        all_char_set.insert(curr_cow.begin(), curr_cow.end());
        cows.push_back(curr_cow);
    }

    vector<string> all_chars(all_char_set.begin(), all_char_set.end());

    for (int a = 0; a < all_char_set.size(); a++)
    {
        for (int b = a + 1; b < all_char_set.size(); b++)
        {
            bool both = false, only_a = false, only_b = false;
            for (const set<string> &c : cows)
            {
                bool has_a = c.count(all_chars[a]);
                bool has_b = c.count(all_chars[b]);

                if (has_a && has_b)
                    both = true;
                else if (has_a && !has_b)
                    only_a = true;
                else if (!has_a && has_b)
                    only_b = true;
            }
            if (both && only_a && only_b)
            {
                fout << "no" << endl;
                return 0;
            }
        }
    }

    fout << "yes" << endl;
}