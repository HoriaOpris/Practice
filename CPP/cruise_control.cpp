#include <iostream>
#include <fstream>

using namespace std;

float actual_speed;
float target_speed;
float throttle;
float debug_steps_cnt;


int main() {
    while(1)
    {
        cout <<"Enter desired speed:";
        cin >> target_speed;
        debug_steps_cnt = 0;
        ofstream MyFile("simulation.csv");
        MyFile << "time,target_speed,actual_speed,throttle" <<endl;

        while(actual_speed != target_speed)
        {
            debug_steps_cnt++;

            if(target_speed > actual_speed)
            {
                actual_speed++;
            }
            else if(target_speed < actual_speed)
            {
                actual_speed--;
            }
            
            MyFile << debug_steps_cnt << "," << target_speed << "," << actual_speed << "," << throttle << endl;
        }

        cout << "Debug steps: " << debug_steps_cnt << endl;
        MyFile.close();
    }


    return 0;
}