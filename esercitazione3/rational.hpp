#include <iostream>
#pragma once
template<typename I> requires std::integral<I>
class rational {
    I num_;
    I den_;
	bool is_inf_ = false;
	bool is_nan_ = false;
	/*semplificazione tramite euclide*/
	I calcola_mcd(I a, I b) {
		if (a<0) {
			a=-a;
		}
		if (b<0) {
			b=-b;
		}
		while (b != 0) {
			I temp=b;
			b=a%b;
			a= temp;
		}
		return a;
	}
			
public:
    bool inf() const { return is_inf_;}
	bool nan() const { return is_nan_;}
     /* costruttore di default*/
    rational()
	     : num_(I{0}), den_(I{1})
	{}
	/*construttore user-defined*/
	rational(const I& pnum_, const I& pden_)
	{
		
		if (pden_ == 0 && pnum_==0) {
			
			is_nan_=true;
			is_inf_=false;
			num_=0;
			den_=0;
				
		} 
		else if (pden_ == 0 && pnum_!=0) {
			is_inf_=true;
			is_nan_=false;
			num_=1;
			den_=0;
				
		}
		
		else {
			is_inf_=false;
			is_nan_=false;
			I comune= calcola_mcd(pnum_, pden_);
			num_=pnum_/comune;
			den_=pden_/comune;
		if (den_ < 0) {
			num_=-num_;
			den_=-den_;
		}
		}
	}
	
	I num() const { return num_; }
	I den() const { return den_; }
	/* implementazione incremento */
	rational& operator+=(const rational& other) {
		long nuovo_num= (this->num_ * other.den()) + (other.num() * this->den_);
		long nuovo_den= (this->den_ * other.den());
		I comune= calcola_mcd(nuovo_num, nuovo_den);
		if (comune!=0) {
			this->num_ = nuovo_num/comune;
			this->den_ = nuovo_den/comune;
		} else {
			this->num_ = nuovo_num;
			this->den_ = nuovo_den;
		}
		return *this;
	}
	
	/* implementazione somma */
	rational operator+(const rational& other) const {
		rational ret=*this;
		ret += other;
		return ret;
	}
	
	/* implementazione differenza composta */
	rational& operator-=(const rational& other) {
		long nuovo_num= (this->num_ * other.den()) - (other.num() * this->den_);
		long nuovo_den= (this->den_ * other.den());
		I comune= calcola_mcd(nuovo_num, nuovo_den);
		if (comune!=0) {
			this->num_ = nuovo_num/comune;
			this->den_ = nuovo_den/comune;
		} else {
			this->num_ = nuovo_num;
			this->den_ = nuovo_den;
		}
		return *this;
	}
	
	/* implementazione differenza */
	rational operator-(const rational& other) const {
		rational ret=*this;
		ret -= other;
		return ret;
	}
	
	/* implementazione moltiplicazione composta */
	rational& operator*=(const rational& other) {
		num_ *= other.num();
		den_ *= other.den();
		I comune= calcola_mcd(num_, den_);
		if (comune!=0) {
			this->num_=num_/comune;
			this->den_=den_/comune;
		}
		
		return *this;
	}
	
	/* implementazione moltiplicazione */
	rational operator*(const rational& other) const {
		rational ret=*this;
		ret *= other;
		return ret;
	}
	
	/* implementazione divisione composta */
	rational& operator/=(const rational& other) {
		long nuovo_num= this->num_*other.den();
		long nuovo_den= this->den_*other.num();
		I comune= calcola_mcd(nuovo_num, nuovo_den);
        if (comune!=0) {
			this->num_ = nuovo_num/comune;
			this->den_ = nuovo_den/comune;
		} else {
			this->num_ = nuovo_num;
			this->den_ = nuovo_den;
		}
		return *this;
	}
	
	/* implementazione divisione */
	rational operator/(const rational& other) const {
		rational ret=*this;
		ret/= other;
		return ret;
	}
		
};

template<typename I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& r)
{
	if (r.nan()) {
		os << "NaN";
	}
	else if (r.inf()) {
		os << "inf";
	}
	else {
		os << "(" << r.num() << "/" << r.den() << ")";
	}
    return os;
};

