all:	bdt component client

client:
	@echo "*********************************************"
	@echo "* Making OcaCCD Client...                   *"
	@echo "*********************************************"
	@cd ./Client/src/ && $(MAKE) clean all install

component:
	@echo "*********************************************"
	@echo "* Making OcaCCD Components...               *"
	@echo "*********************************************"
	@cd ./Component/src/ && $(MAKE) clean all install

bdt:
	@echo "*********************************************"
	@echo "* Making Bulk Data Transfer components...   *"
	@echo "*********************************************"
	@cd ./bulkDataTransfer/src/ && $(MAKE) clean all install
	@cd ./bulkDataTransfer/test/ && $(MAKE) clean all install

clean:
	@echo "*********************************************"
	@echo "* Cleaning all...                           *"
	@echo "*********************************************"
	@cd ./Client/src/ && $(MAKE) clean
	@cd ./Component/src/ && $(MAKE) clean
	@cd ./bulkDataTransfer/src/ && $(MAKE) clean
	@cd ./bulkDataTransfer/test/ && $(MAKE) clean
