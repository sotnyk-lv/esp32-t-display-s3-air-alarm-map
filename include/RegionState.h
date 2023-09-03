#ifndef REGION_STATE_H
#define REGION_STATE_H

enum regionStateEnum {
    stateAlert,
    statePeace,
    stateUnknown,
    stateError
};

enum regionsEnum {
	crimeaRegion,
	vinnytsiaRegion,
	volynRegion,
	dnipropetrovskRegion,
	donetskRegion,
	zhytomyrRegion,
	zakarpattiaRegion,
	zaporizhzhiaRegion,
	frankivskRegion,
	kyivRegion,
	kirovohradRegion,
	luhanskRegion,
	lvivRegion,
	mykolaivRegion,
	odesaRegion,
	poltavaRegion,
	rivneRegion,
	sumyRegion,
	ternopilRegion,
	kharkivRegion,
	khersonRegion,
	khmelnytskyiRegion,
	cherkasyRegion,
	chernivtsiRegion,
	chernihivRegion,
	kyivcityRegion,
	unknownRegion,
};

struct RegionState {

    RegionState(int region, int state) : region{region}, state{state} {};

    int region;
    int state;
};

#endif // REGION_STATE_H