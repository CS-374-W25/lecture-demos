int main() {
	int x;
	int* p = &x;
	
	void* vp = &x;
	int* casted_vp = (int*) vp;
	*casted_vp = 10;
}
