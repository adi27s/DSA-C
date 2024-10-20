class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int length = nums.size();
        vector<int> v1(length, 1);
        vector<int> v2(length, 1);
        vector<int> answer(length);

        int temp1 = 1, temp2 = 1;

        for (int i = 0; i < length; ++i)
        {
            temp1 *= nums[i];
            v1[i] = temp1;
        }

        for (int j = length - 1; j >= 0; --j)
        {
            temp2 *= nums[j];
            v2[j] = temp2;
        }

        for (int i = 0; i < length; ++i)
        {
            if (i == 0)
            {
                answer[i] = (v2[1]);
            }
            else if (i == length - 1)
            {
                answer[i] = v1[length - 2];
            }
            else
            {
                answer[i] = v1[i - 1] * v2[i + 1];
            }
        }

        return answer;
    }
};