#pragma once
public class {
	void needUnfufilled(NEEDS need) {



		switch (need)
		{
		case HUNGER:
			starving();
			break;
		case THIRST:
			dehydrated();
			break;
		case SLEEP:
			exhausted();
			break;
		case OXYGEN:
			knockOut();
			break;
		default:
			break;
		}
	}
};
