all:	bdt component client

client:
	@echo "*********************************************"
	@echo "* Making gCCD Client...                     *"
	@echo "*********************************************"
	@cd ./gCCDGUIClient/src/ && $(MAKE) clean all install

component:
	@echo "*********************************************"
	@echo "* Making gCCD Components...                 *"
	@echo "*********************************************"
	@cd ./gCCDComponent/src/ && $(MAKE) clean all install

bdt:
	@echo "*********************************************"
	@echo "* Making Bulk Data Transfer components...   *"
	@echo "*********************************************"
	@cd ./gCCDBDT/src/ && $(MAKE) clean all install
	@cd ./gCCDBDT/test/ && $(MAKE) clean all install

clean:
	@echo "*********************************************"
	@echo "* Cleaning all...                           *"
	@echo "*********************************************"
	@cd ./gCCDGUIClient/src/ && $(MAKE) clean
	@cd ./gCCDComponent/src/ && $(MAKE) clean
	@cd ./gCCDBDT/src/ && $(MAKE) clean
	@cd ./gCCDBDT/test/ && $(MAKE) clean
