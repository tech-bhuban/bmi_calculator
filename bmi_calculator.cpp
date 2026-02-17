

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

class BMICalculator {
private:
    double weight;
    double height;
    std::string name;
    
public:
    BMICalculator(std::string n, double w, double h) 
        : name(n), weight(w), height(h) {}
    
    double calculateBMI() {
        return weight / (height * height);
    }
    
    std::string getCategory() {
        double bmi = calculateBMI();
        if(bmi < 18.5) return "Underweight";
        if(bmi < 25) return "Normal weight";
        if(bmi < 30) return "Overweight";
        return "Obese";
    }
    
    std::string getHealthAdvice() {
        double bmi = calculateBMI();
        if(bmi < 18.5) 
            return "Consider gaining weight with healthy foods and exercise";
        if(bmi < 25) 
            return "Maintain your healthy lifestyle with balanced diet";
        if(bmi < 30) 
            return "Consider regular exercise and portion control";
        return "Consult a healthcare provider for weight management";
    }
    
    double idealWeight() {
        return 22.0 * (height * height); // BMI 22 is ideal
    }
    
    void printReport() {
        double bmi = calculateBMI();
        std::cout << "\n=== BMI Report for " << name << " ===\n";
        std::cout << "Height: " << height << " m\n";
        std::cout << "Weight: " << weight << " kg\n";
        std::cout << "BMI: " << std::fixed << std::setprecision(1) << bmi << "\n";
        std::cout << "Category: " << getCategory() << "\n";
        std::cout << "Ideal weight: " << idealWeight() << " kg\n";
        std::cout << "Advice: " << getHealthAdvice() << "\n";
    }
};

int main() {
    std::string name;
    double weight, height;
    
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Enter weight (kg): ";
    std::cin >> weight;
    std::cout << "Enter height (m): ";
    std::cin >> height;
    
    BMICalculator person(name, weight, height);
    person.printReport();
    return 0;
}


