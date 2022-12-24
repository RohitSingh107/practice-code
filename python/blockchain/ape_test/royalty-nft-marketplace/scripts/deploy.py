from ape import accounts, project, Contract
from ape.api.accounts import AccountAPI
from ape.cli import get_user_selected_account 

def deployMarketplace(deployer : AccountAPI, publish : bool):
    print(f"Using account {deployer}")
    print(f"Account balance is {deployer.balance / 1e18}")
    print(f"Chain: {deployer.provider}")

    deployer.deploy(project.Marketplace, publish=publish) # publish to verify contract on etherscan/polygonscan

def deployNFT(deployer : AccountAPI, publish : bool):
    print(f"Using account {deployer}")
    print(f"Account balance is {deployer.balance / 1e18}")
    print(f"Chain: {deployer.provider}")

    deployer.deploy(project.AANFT, publish=publish) # publish to verify contract on etherscan/polygonscan





def main():
    # deployer = accounts.load("rohit_dev")
    deployer = get_user_selected_account() 

    deployMarketplace(deployer=deployer,publish= True)
    deployNFT(deployer=deployer,publish= True)



