class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> v;
        
        double kelvin, fahrenheit;
        
        kelvin = celsius + 273.15;
        fahrenheit = celsius * 1.80 + 32.00;
        
        v.push_back(kelvin);
        v.push_back(fahrenheit);
        return v;
    }
};