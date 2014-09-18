#include "MonkeyObject.h"
#include "RobotObject.h"
class RobotMonkeyObject : public RobotObject, public MonkeyObject {

	private:
		int speed;
	public:
		RobotMonkeyObject();

		int getSpeed(){
			return speed;
		}
};
