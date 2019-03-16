#include <stdio.h>
#include <string.h>

typedef struct {
	int hours;
	int mins;
} m_time ;


m_time add_time(m_time a, m_time b);
int get_hour(m_time c);
int get_min(m_time c);
void set_time(m_time *p, int y, int z);

 int main(){
	m_time  a, b, c;
	int  h, m;

 	set_time(&a, 3, 30);
	set_time(&b, 2, 40);

	c = add_time(a, b);  
	h = get_hour(c);
	m = get_min(c);

	printf(" C :  %d hours and %d mins.\\n", h, m);
    /* ¡®C : 6 hours and 10 mins.¡¯ is expected.. */
}

void set_time(m_time *p,int y, int z) {
	p->hours =y;
    p->mins =z;  
}

m_time add_time(m_time a,m_time b) {
	m_time c;
	c.hours = a.hours+ b.hours;
	c.mins = a.mins + b.mins;

	return c;
} 


int get_hour(m_time c) {
	int h = c.hours+c.mins/60;
	return h;
}

int get_min(m_time c) {
	int m;
	if (c.mins > 59) 
		m = c.mins %60;
	else
		m = c.mins;

	return m;
} 