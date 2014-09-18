
class RobotObject {
	
	private:
		bool bMeleeWeapon;
		bool bRangedWeapon;
		int speed;
	public:
		RobotObject(bool melee, bool ranged);
		bool hasMeleeWeapon(){
			return bMeleeWeapon;
		}


};
