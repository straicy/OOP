class Ceh {
private:
    const char* name; // означає, що ми не будемо змінювати сам рядок через цей вказівник.
public:
	Ceh() : name(nullptr) {} // конструктор без параметрів
	Ceh(const char* n) : name(n) {} // конструктор з параметром

	const char* getName() const { return name; } // просто повертаємо вказівник
    void setName(const char* n) { name = n; } // просто присвоюємо вказівник
};
