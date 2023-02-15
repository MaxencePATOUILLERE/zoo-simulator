#include <iostream>

using namespace std;

int buy_sell_animal(){
    int buy_sell = 0;
    cout << "1. Do you want to buy ?\n2. Or sell ?" << endl;
    cin >> buy_sell;
    return buy_sell;
}

int choose_animal(){
    int animal = 0;
    cout << "1. Do you want a tiger?\n2. Do you want a eagle?\n3. Do you want a chicken?" << endl;
    cin >> animal;
    return animal;
}

int genre_animal(){
    int genre = 0;
    cout << "1. A male?\n2. A female?" << endl;
    cin >> genre;
    return genre;
}

int choose_age_animal(){
    int seniority = 0;
    cout << "1. Old?\n2. Middle age?\n3. Young?" << endl;
    cin >> seniority;
    return seniority;   
}

int main(){
    string zoo_name = "";
    cin >> zoo_name;
    Zoo* zoo(zoo_name);
    Male_tiger* pumba("pumba", 24);
    Female_tiger* tigresse("tigresse", 72);
    Female_tiger* tatigresse("tatigresse", 36);
    Male_eagle* eagloo("eagloo", 48);
    Male_eagle* glouglou("glouglou", 36);
    Female_eagle* lapiaf("lapiaf", 168);
    Female_eagle* lapignouf("lapignouf", 60);
    Rooster* fried_chicken("fried_chicken", 6);
    Chicken* poulette("poulette", 6);
    Chicken* poule("poule", 5);
    Chicken* poulet("poulet", 7);
    Chicken* oulet("oulet", 1);
    Chicken* ctropbon("ctropbon", 2);
    Chicken* kfc("kfc", 3);
    Chicken* bucket("bucket", 4);
    Chicken* roti("roti", 8);
    Chicken* teriyaki("teriyaki", 9);
    Chicken* braise("braise", 10);
    
    while(1){
        int action = 0;
        cout << "Choose an action:\n1. Buy/Sell animal\n2. Buy food\n3. Buy/Sell habitat\n4. Next turn" << endl;
        cin >> action;
        switch (action)
        {
        case 1:
        if(buy_sell_animal()==1){
            switch(choose_animal())
            {
                case 1:
                if(genre_animal()==1){
                    string tiger_name = "";
                    cout << "Choose name: ";
                    cin >> tiger_name;
                    if(choose_age_animal()==1){
                        Male_tiger* tigrou(tiger_name, 168);
                    }else if(choose_age_animal()==2){
                        Male_tiger* tigrou(tiger_name, 48);                       
                    }else{
                        Male_tiger* tigrou(tiger_name, 6); 
                    }
                }else{
                    string tiger_name = "";
                    cout << "Choose name: ";
                    cin >> tiger_name;
                    if(choose_age_animal()==1){
                        Female_tiger* tatigresse(tiger_name, 168);
                    }else if(choose_age_animal()==2){
                        Female_tiger* tatigresse(tiger_name, 48);                       
                    }else{
                        Female_tiger* tatigresse(tiger_name, 6);                       
                    }
                }
                break;
                case 2:
                if(genre_animal()==1){
                    string eagle_name = "";
                    cout << "Choose name: ";
                    cin >> eagle_name;
                    if(choose_age_animal()==1){
                        Male_eagle* eagloo(eagle_name, 168);
                    }else if(choose_age_animal()==2){
                        Male_eagle* eagloo(eagle_name, 48);
                    }else{
                        Male_eagle* eagloo(eagle_name, 6);
                    }
                }else{
                    string eagle_name = "";
                    cout << "Choose name: ";
                    cin >> eagle_name;
                    if(choose_age_animal()==1){
                        Female_eagle* lapiaf(eagle_name, 168);
                    }else if(choose_age_animal()==2){
                        Female_eagle* lapiaf(eagle_name, 48);                       
                    }else{
                        Female_eagle* lapiaf(eagle_name, 6);
                    }
                }
                break;
                case 3:
                if(genre_animal()==1){
                    string rooster_name = "";
                    cout << "Choose name: ";
                    cin >> rooster_name;
                    Rooster* fried_chicken(rooster_name, 6);
                }else{
                    string chicken_name = "";
                    cout << "Choose name: ";
                    cin >> chicken_name;
                    Chicken* poulette(chicken_name, 6);
                }
                break;
            }
        }else{
            //coder la revente d'un animal
        }
            break;
        default:
            break;
        }
    };
    return 0;
}