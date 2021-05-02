#include<vector>
#include<string>

class Drob
{
    public:
    	int x, y;
    	Drob ();
    	Drob (int x, int y);
    	~Drob();
    	void set_x(int _x);
    	void set_y(int _y);
    	int  get_x();
    	int  get_y();
    	void ration();
	friend Drob  operator +  (Drob&, Drob&);
	friend Drob  operator -  (Drob&, Drob&); 
};

class Accountant : public Drob
{
	private:
		int z;
	public:
		Accountant();
		Accountant (int, int, int);
    		~Accountant();
    		void set_x(int _x);
    		void set_y(int _y);
    		void set_z(int _z);
    		int  get_x();
    		int  get_y();
    		int  get_z();
    		void ration();
		friend Accountant  operator +  (Accountant&, Accountant&);
		friend Accountant  operator -  (Accountant&, Accountant&); 
};

template<typename A>
class Negotiation
{
	private:
		std::vector<std::string> att_students;
		A time;
	public:
		Negotiation();
		Negotiation(A);
		Negotiation(A, std::vector<std::string>);
    		~Negotiation();
    		void set_time(A _time);
    		void set_students(std::vector<std::string>);
    		void add_student(std::string);
    		A  get_time();
    		std::vector<std::string>  get_students();
		template<typename B>friend Negotiation  operator +  (Negotiation<B>&, B&);
		template<typename B>friend Negotiation  operator -  (Negotiation<B>&, B&);
	
};
