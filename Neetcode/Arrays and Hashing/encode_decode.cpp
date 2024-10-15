class Solution
{
public:
    string encode(vector<string> &strs)
    {
        // cout << "###### ENCODE ######" << endl;
        string send;
        int num_of_strings = 0;
        int size = 0;

        for (auto i : strs)
        {
            string init = "";
            size = i.size();
            if ((size / 100) == 0)
            {
                // not a 3 digit number
                if ((size / 10) == 0)
                {
                    // not a 2 digit number
                    init.append("00");
                    init.append(to_string(size));
                }
                else
                {
                    init.append("0");
                    init.append(to_string(size));
                }
            }
            else
            {
                init.append(to_string(size));
            }
            send.append(init);
            send.append(i);
            ++num_of_strings;
            // cout << send << endl;
        }

        string init = ""; // Declare `init` here
        if ((num_of_strings / 100) == 0)
        {
            // not a 3 digit number
            if ((num_of_strings / 10) == 0)
            {
                // not a 2 digit number
                init.append("00");
                init.append(to_string(num_of_strings));
            }
            else
            {
                init.append("0");
                init.append(to_string(num_of_strings));
            }
        }
        else
        {
            init.append(to_string(num_of_strings));
        }

        send.append(init);
        return send;
    }

    vector<string> decode(string s)
    {
        cout << "###### DECODE ######" << endl;
        int length = s.size();
        int num_of_strings = stoi(s.substr(length - 3, 3));
        int letters = 0;
        vector<string> v;
        int index = 0;
        while (num_of_strings != 0)
        {
            letters = stoi(s.substr(index, 3));
            cout << letters << " ";
            cout << s.substr(index + 3, letters) << endl;
            v.push_back(s.substr(index + 3, letters));
            index = index + letters + 3;
            --num_of_strings;
        }
        return v;
    }
};