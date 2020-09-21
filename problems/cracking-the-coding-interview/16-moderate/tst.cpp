#include <bits/stdc++.h>

using namespace std;

int main()
{
    // read the string filename
    string filename;
    cin >> filename;

    // Create map to store host name counts
    map<string, int> map;

    // Open file stream
    ifstream file(filename);

    // Process file;
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            // Get hostname
            int space_index = line.find(' ');
            string hostName = line.substr(0, space_index);

            // Insert into map if needed
            if (map.find(hostName) == map.end()) {
                map.insert(pair<string, int>({ hostName, 0 }));
            }

            // Increment host name count
            map[hostName]++;
        }

        // Close file
        file.close();
    }

    // Create output file name
    string outputName = "records_" + filename;

    // Open ouput stream
    ofstream output(outputName);

    // Output results
    if (output.is_open()) {
        for (auto it = map.begin(); it != map.end(); ++it) {
            output << (*it).first << " " << (*it).second << endl;
        }

        // Close
        output.close();
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

int num_ones(int i)
{
    int count = 0;
    while (i != 0) {
        count += i & 1;
        i = i >> 1;
    }

    return count;
}

bool num_ones_compare(int first, int second)
{
    return num_ones(first) < num_ones(second);
}

/*
 * Complete the 'rearrange' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY elements as parameter.
 */

vector<int> rearrange(vector<int> elements)
{

    // Sort by decimal value
    std::stable_sort(elements.begin(), elements.end());

    // Sort by number of bits
    std::stable_sort(elements.begin(), elements.end(), num_ones_compare);

    return elements;
}
