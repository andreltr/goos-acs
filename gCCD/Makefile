all:	bdt component client

client:
	@echo "*********************************************"
	@echo "* Making OcaCCD Client...                   *"
	@echo "*********************************************"
	@cd ./gCCD_GUIClient/src/ && $(MAKE) clean all install

component:
	@echo "*********************************************"
	@echo "* Making OcaCCD Components...               *"
	@echo "*********************************************"
	@cd ./gCCD_Component/src/ && $(MAKE) clean all install

bdt:
	@echo "*********************************************"
	@echo "* Making Bulk Data Transfer components...   *"
	@echo "*********************************************"
	@cd ./gCCD_BDT/src/ && $(MAKE) clean all install
	@cd ./gCCD_BDT/test/ && $(MAKE) clean all install

clean:
	@echo "*********************************************"
	@echo "* Cleaning all...                           *"
	@echo "*********************************************"
	@cd ./gCCD_GUIClient/src/ && $(MAKE) clean
	@cd ./gCCD_Component/src/ && $(MAKE) clean
	@cd ./gCCD_BDT/src/ && $(MAKE) clean
	@cd ./gCCD_BDT/test/ && $(MAKE) clean
