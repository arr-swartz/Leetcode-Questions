class ParkingSystem {
public:
    int nbb;
    int sbb;
    int nmm;
    int smm;
    int nss;
    int sss;
    ParkingSystem(int big, int medium, int small) {
        nbb  =0;
        sbb = big;
        nmm = 0;
        smm = medium;
        nss = 0;
        sss = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            if(nbb == sbb){
                return false;
            }
            else{
                nbb++;
                return true;
            }
        }else if(carType == 2){
            if(nmm == smm){
                return false;
            }
            else{
                nmm++;
                return true;
            }
        }else if(carType == 3){
            if(nss == sss){
                return false;
            }
            else{
                nss++;
                return true;
            }
        }else{
            return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */