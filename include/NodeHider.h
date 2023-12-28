#pragma once

namespace DeviousDevices
{
    //for implementing this, I used https://github.com/ArranzCNL/ImprovedCameraSE-NG as reference which also hides arms using nodes
    class NodeHider
    {
    SINGLETONHEADER(NodeHider)
    public:
        enum HidderState : uint8_t
        {
            sShown  = 0,
            sHidden = 1
        };

        void HideArms(RE::Actor* a_actor);
        void ShowArms(RE::Actor* a_actor);
        void UpdateArms(RE::Actor* a_actor);

        //https://wiki.beyondskyrim.org/wiki/Arcane_University:Nifskope_Weapons_Setup
        void HideWeapons(RE::Actor* a_actor);
        void ShowWeapons(RE::Actor* a_actor);
        void UpdateWapons(RE::Actor* a_actor);

        void Setup();
        void Update();
        void Reload();
    protected:
        bool ActorIsValid(RE::Actor* a_actor) const;
        bool ShouldHideWeapons(RE::Actor* a_actor) const;
        bool AddHideNode(RE::Actor* a_actor, std::string a_nodename);
        bool RemoveHideNode(RE::Actor* a_actor, std::string a_nodename);

    private:
        bool _installed = false;
        RE::BGSKeyword*             _straitjacket;
        std::vector<uint32_t>       _lastupdatestack;
        std::vector<std::string>    _WeaponNodes;
        std::vector<std::string>    _ArmNodes;
        std::unordered_map<uint32_t,HidderState> _armhiddenstates;    //temporary array with state of arm nodes on updated actors
        std::unordered_map<uint32_t,HidderState> _weaponhiddenstates; //temporary array with state of weapon nodes on updated actors
    };
}