#define SegA 4
#define SegB 0
#define SegC 17
#define SegD 16
#define SegE 23
#define SegF 19
#define SegG 18
#define DP 5
#define digit10 14
#define digit01 27

int count = 0;
//-----------------------------------
char BIN_TO_7SEGMENT2(char A)
{
	static char LOOKUPTB[] = {
		0x3F,
		0x06,
		0x5B,
		0x4F,
		0x66,
		0x6D,
		0x7D,
		0x07,
		0x7F,
		0x6F,
		0x77,
		0x7C,
		0x39,
		0x5E,
		0x79,
		0x71
	};

	return LOOKUPTB[A];
}

void display7segment(char data)
{
	(data & 0x01)? digitalWrite(SegA, HIGH):digitalWrite(SegA, LOW);
	(data & 0x02)? digitalWrite(SegB, HIGH):digitalWrite(SegB, LOW);
	(data & 0x04)? digitalWrite(SegC, HIGH):digitalWrite(SegC, LOW);
	(data & 0x08)? digitalWrite(SegD, HIGH):digitalWrite(SegD, LOW);
	(data & 0x10)? digitalWrite(SegE, HIGH):digitalWrite(SegE, LOW);
	(data & 0x20)? digitalWrite(SegF, HIGH):digitalWrite(SegF, LOW);
	(data & 0x40)? digitalWrite(SegG, HIGH):digitalWrite(SegG, LOW);

}

void setup() {
	pinMode(SegA, OUTPUT);
	pinMode(SegB, OUTPUT);
	pinMode(SegC, OUTPUT);
	pinMode(SegD, OUTPUT);	
	pinMode(SegE, OUTPUT);
	pinMode(SegF, OUTPUT);
	pinMode(SegG, OUTPUT);
	pinMode(DP, OUTPUT);
	pinMode(digit10, OUTPUT);
	pinMode(digit01, OUTPUT);
}

void countDec(char mode)
{
	int dig01, dig10;
	char tmp;

	dig01 = count % 10;
	dig10 = count / 10;

	tmp = BIN_TO_7SEGMENT2(dig01);
	display7segment(tmp);

	digitalWrite(digit01, HIGH);
	digitalWrite(digit10, LOW);
	delay(500);

	tmp = BIN_TO7SEGMENT2(dig10);
	display7segment(tmp);

	digitalWrite(digit01, LOW);
	digitalWrite(digit10, HIGH);
	delay(500);

	if(mode)
	{
		count = (count + 1)%100;
	}
	else
	{
		count = (count - 1 + 100)%100;
	}
}
void loop() {
	int i, dg01, dg10;
	char tmp;

	for(i = 0; i<100; i++)
	{
		dg01 = i % 10;
		dg10 = i / 10;

		tmp = BIN_TO_7SEGMENT2(dg01);
		display7segment(tmp);

		digitalWrite(digit01, HIGH);
		digitalWrite(digit10, LOW);

		delay(500);

		tmp = BIN_TO_7SEGMENT2(dg10);
		display7segment(tmp);

		digitalWrite(digit01, LOW);
		digitalWrite(digit10, HIGH);

		delay(500);
	}
}
