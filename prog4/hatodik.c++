#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    std::vector<int> v; //{}

    for (int i=0; i<10; i++){
        v.push_back(i*10);
        cout << v[i] << " " << v.at(i) << " " << v.capacity() << " " << v.data() << endl;
    }

    //cout << v.at(50) << endl;

    v[0] =15;
    v.at(9)=10;
    cout << v[0] << " " << v[9] << endl;

    //v[12]=150;
    //cout << v[12] << endl;
    //cout << v.at(12) << endl;
    for(int i:v){
        cout << i << " ";
    }
    cout << endl;

    v.shrink_to_fit();
    cout << v.capacity() << " " << v.size() << endl;

    v.clear();

    v= {2,2,3,1,2,5,7,4,8,3};

    //Növekvő sorrend
    sort(v.begin(), v.end());
    for(int szam:v){
        cout << szam << " ";
    }
    cout << endl;

    //Maximum kiválasztás pozícióval
    int max= v[0];
    int maxind = 0;

    for(int i=0; i< v.size(); i++){
        if(max < v[i]){
            max=v[i];
            maxind= i;
        }
    }
    cout << "A vektor maximuma: " << max << ", pozíciója: " << maxind << endl;

    //Minimum kiválasztás pozícióval
    int min= v[0];
    int minind = 0;

    for(int i=0; i< v.size(); i++){
        if(min > v[i]){
            min=v[i];
            minind= i;
        }
    }
    cout << "A vektor minimuma: " << min << ", pozíciója: " << minind << endl;

    //megszámlálás:
    //hány xy feltételnek megfelelő elem található a konténerben
    //feltétel érték = 2

    int count= 0;
    for(int i:v){
        if(i==2){
            count++;
        }
    }
    cout << "A konténerben " << count << "db 2-es található" << endl;

    //szétválasztás:
    //válogassuk külön azokat az elemeket, amelyek megfelelnek/ nem felelnek meg egy feltételnek
    //válogassuk szét az átlagtól kisebb és nagyobb elemeket

    int atlag=0;
    for (int i:v){
        atlag+=i;
    }
    atlag/=v.size();

    vector<int> kisebb;
    vector<int> nagyobb;

    for (int i:v){
        if(i<atlag){
            kisebb.push_back(i);
        }
        if(i>atlag){
            nagyobb.push_back(i);
        }
    }
    cout << "Átlagtól kisebb: " << endl;
    for (int i:kisebb){
        cout << i << " ";
    } cout << endl;

    cout << "Átlagtól nagyobb: " << endl;
    for (int i:nagyobb){
        cout << i << " ";
    } cout << endl;

    //Számoljuk meg a vektorban található prímszámokat
}