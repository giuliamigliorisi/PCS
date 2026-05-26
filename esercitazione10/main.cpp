#include <iostream>
#include <Eigen/Dense>
#include <cmath> // Per std::abs
#include "gradiente_coniugato.hpp" 


double condA(const Eigen::MatrixXd& matrix) {
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(matrix);
    double max_singular_value = svd.singularValues()(0);
    double min_singular_value = svd.singularValues()(svd.singularValues().size() - 1);
    
    if (min_singular_value == 0) return 0.0; 
    return max_singular_value / min_singular_value;
}

int main() {
    
    int n = 3; 
    double tol = 1e-6;               
    unsigned int maxIter = 100;           
    unsigned int it = 0;             
    
    Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);
    
    if (std::abs(B.determinant()) < 1e-15) {
        std::cout << "Matrice non invertibile" << std::endl;
        return -1;
    }
    
    
    Eigen::MatrixXd A = B.transpose() * B;
    
    Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);
    
    
    Eigen::VectorXd b = A * x_ex;
    
    Eigen::VectorXd x0 = Eigen::VectorXd::Zero(n);
    
    Eigen::VectorXd x = gradiente_coniugato(A, b, x0, tol, maxIter, it);
    
    
    std::cout << "Test gradiente coniugato\n";
    
    std::cout << "Cond(A): " << condA(A) << std::endl;
    
    std::cout << "Iterazioni: " << it << std::endl;
    

    double err_rel = (x_ex.norm() == 0.0) 
                     ? (x - x_ex).norm() 
                     : (x - x_ex).norm() / x_ex.norm();
                     

    std::cout << "Errore relativo: " << err_rel << std::endl;
    

    Eigen::VectorXd res_matematico = b - A * x;
    std::cout << "Residuo finale: " << res_matematico.norm() << std::endl;
    
    
    std::cout << "Soluzione numerica:\n" << x << std::endl;
    
    
    std::cout << "Soluzione esatta:\n" << x_ex << std::endl;
    
    return 0;
}