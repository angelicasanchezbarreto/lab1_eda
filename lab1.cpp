#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <chrono>

using namespace std;

typedef tuple<int,int,float> ktuple;

struct sort_points{
    bool operator()(ktuple const &p1, ktuple const &p2){
        return get<2>(p1) < get<2>(p2);
    }
};

vector<ktuple> kvecinos(int k, vector<pair<int,int>> points, pair<int,int> p_base){
    int x,y;
    vector<ktuple> output;
    //cout << "Base point: (" << p_base.first << "," << p_base.second << ")\n";
    for(int i=0; i<points.size();i++){ // O(size)
        int x = points[i].first;
        int y = points[i].second;
        if(x!=p_base.first && x!=p_base.second){
            float dist = pow(pow((p_base.first - x),2)+pow((p_base.second-y),2),0.5);
            ktuple point{x,y,dist};
            output.push_back(point);
        }
    }
    sort(begin(output),end(output),sort_points()); // O(size)
    vector<ktuple> output2(output.begin(),output.begin()+k);
    return output2;
}

vector<pair<int,int>> read_file(string name){
    fstream file(name);
    vector<pair<int,int>> result;
    vector<int> row1, row2;
    string line1, line2, num1, num2, temp;
    while(file >> line1 >> line2){
        stringstream s1(line1);
        stringstream s2(line2);

        while(getline(s1,num1,',') && getline(s2,num2,',')){ //  O(size)
            row1.push_back(stoi(num1));
            row2.push_back(stoi(num2));
        }
    }

    for(int i = 0; i < row1.size(); i++){ // O(size)
        pair<int, int> temporal{row1[i],row2[i]}; 
        result.push_back(temporal);
    }

    return result;
}

void print_point(ktuple point){
    cout << "X: " << get<0>(point) << " Y: " << get<1>(point) << " Dist: " << get<2>(point);
}

void get_times(vector<pair<int,int>> file, int num_experiments, int k){
    srand(time(NULL));
    for(int i=0; i<num_experiments; i++){
        auto begin = chrono::high_resolution_clock::now();
        vector<ktuple> result = kvecinos(k, file, file[rand()%50001]);
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - begin);
        cout << elapsed.count() << " ";
    }
}

int main(){
    vector<pair<int,int>> fileA = read_file("dsA.csv");
    vector<pair<int,int>> fileB = read_file("dsB.csv");
    vector<pair<int,int>> fileC = read_file("dsC.csv");

    get_times(fileB,5000,5);

    /* fstream myReadFile;
    myReadFile.open("times.txt");
    float output;
    if (myReadFile.is_open()) {
        while (!myReadFile.eof()) {
            myReadFile >> output;
            cout << output << " ";
        }
    } */

    return 0;
}