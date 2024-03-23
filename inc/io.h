/* Interface for generic IO drivers */
class IO {
public:
	virtual void write_byte(char) = 0;
};
