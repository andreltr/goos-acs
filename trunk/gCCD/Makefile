all:	bdt component client

client:
	@echo "*********************************************"
	@echo "* Making OcaCCD Client...                   *"
	@echo "*********************************************"
	@cd ./luckyGUIClient/src/ && $(MAKE) clean all install

component:
	@echo "*********************************************"
	@echo "* Making OcaCCD Components...               *"
	@echo "*********************************************"
	@cd ./luckyComponent/src/ && $(MAKE) clean all install

bdt:
	@echo "*********************************************"
	@echo "* Making Bulk Data Transfer components...   *"
	@echo "*********************************************"
	@cd ./luckyBDT/src/ && $(MAKE) clean all install
	@cd ./luckyBDT/test/ && $(MAKE) clean all install

clean:
	@echo "*********************************************"
	@echo "* Cleaning all...                           *"
	@echo "*********************************************"
	@cd ./luckyGUIClient/src/ && $(MAKE) clean
	@cd ./luckyComponent/src/ && $(MAKE) clean
	@cd ./luckyBDT/src/ && $(MAKE) clean
	@cd ./luckyBDT/test/ && $(MAKE) clean
