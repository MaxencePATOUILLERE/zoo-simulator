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

int choose_food(){
    int food = 0;
    cout << "1. Buy meat?\n2. Buy seed?" << endl;
    cin >> food;
    return food;
}

int main(){
    string zoo_name = "";
    cin >> zoo_name;
    Zoo* zoo(zoo_name);

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
                string tiger_name = ""; // ici on demande le nom avant le genre. Pas logique mais ça prend moins de lignes.
                cout << "Choose name: ";
                cin >> tiger_name;
                if(genre_animal()==1){
                    if(choose_age_animal()==1){
                        Male_tiger* old_tiger = new Male_tiger(tiger_name, 168);
                        zoo->buyAnimal(old_tiger);
                        // afficher les sous en moins quand on buy un animal
                        // afficher les caractéristiques de l'animal ???
                    }else if(choose_age_animal()==2){
                        Male_tiger* tiger = new Male_tiger(tiger_name, 48);
                        zoo->buyAnimal(tiger);                       
                    }else{
                        Male_tiger* young_tiger = new Male_tiger(tiger_name, 6); 
                        zoo->buyAnimal(young_tiger);                       
                    }
                }else{
                    if(choose_age_animal()==1){
                        Female_tiger* old_tatigresse = new Female_tiger(tiger_name, 168);
                        zoo->buyAnimal(old_tatigresse);                       
                    }else if(choose_age_animal()==2){
                        Female_tiger* tatigresse = new Female_tiger(tiger_name, 48);    
                        zoo->buyAnimal(tatigresse);                       
                    }else{
                        Female_tiger* young_tatigresse = new Female_tiger(tiger_name, 6);                       
                        zoo->buyAnimal(young_tatigresse);                       
                    }
                }
                break;
                case 2:
                string eagle_name = "";
                cout << "Choose name: ";
                cin >> eagle_name;
                if(genre_animal()==1){
                    if(choose_age_animal()==1){
                        Male_eagle* old_eagloo = new Male_eagle(eagle_name, 168);
                        zoo->buyAnimal(old_eagloo);
                    }else if(choose_age_animal()==2){
                        Male_eagle* eagloo = new Male_eagle(eagle_name, 48);
                        zoo->buyAnimal(eagloo);
                    }else{
                        Male_eagle* young_eagloo = new Male_eagle(eagle_name, 6);
                        zoo->buyAnimal(young_eagloo);
                    }
                }else{
                    if(choose_age_animal()==1){
                        Female_eagle* old_lapiaf = new Female_eagle(eagle_name, 168);
                        zoo->buyAnimal(old_lapiaf);
                    }else if(choose_age_animal()==2){
                        Female_eagle* lapiaf = new Female_eagle(eagle_name, 48);
                        zoo->buyAnimal(lapiaf);                       
                    }else{
                        Female_eagle* young_lapiaf = new Female_eagle(eagle_name, 6);
                        zoo->buyAnimal(young_lapiaf);
                    }
                }
                break;
                case 3:
                string chicken_name = "";
                cout << "Choose name: ";
                cin >> chicken_name;
                if(genre_animal()==1){
                    Rooster* fried_chicken = new Rooster(chicken_name, 6);
                    zoo->buyAnimal(fried_chicken);
                }else{
                    Chicken* poulette = new Chicken(chicken_name, 6);
                    zoo->buyAnimal(poulette);
                }
                break;
            }
        }else{
            // coder la revente d'un animal
        }
            break;
        case 2:
        int kilos = 0;
        cout << "How many kilos do you want to buy?" << endl;
        cin >> kilos;
        if(choose_food()==1){
            Meat* meat = new Meat(kilos);
            zoo->buyFood(meat);
            // afficher les sous en moins quand on buy de la nourriture
        }else{
            Seed* seed = new Seed(kilos);
            zoo->buyFood(seed);
        }

        default:
            break;
        }

    };
    return 0;
}