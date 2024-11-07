#include "emptymenuhandling.h"
void MakeEmptyMenuProgramEntry(TyphonConfig* menucfg, int menu, std::string iconpath){
	TyphonConfig* ProgEntry=menucfg->sub(menu)->sub("entry")->subCa("prog");
	ProgEntry->set("binary","");
	ProgEntry->set("args","");
	ProgEntry->set("name","Empty Menu");
	ProgEntry->set("icon",iconpath);
}

void FixEmptyMenus(TyphonConfig* mecfg){
	//Entry 0 is the "first" entry. If it doesn't exist,
	//no other entries exist either.
	for(int menu = 0; menu <= 6; menu++){
		if(!mecfg->sub(menu)->sub("entry")->sub(0)){
			#ifdef DEBUG
			std::cerr << "\nMenu " << menu << " is empty! Creating fake menuentry.";
			#endif
			MakeEmptyMenuProgramEntry(mecfg, menu, "");
			mecfg->sub(menu)->setBool("empty", true);
		}
		else{
			mecfg->sub(menu)->setBool("empty", false);	
		}
	}
}
