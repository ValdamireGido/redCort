#pragma once 

#include <map>
#include <vector>
#include <istream>
#include <ostream>
#include <string>

namespace redcort
{
	// types
	using SettingId = size_t;

	// fwd 
	class Setting;

	// class SettingCollection - map of settings with version control
	class SettingCollection
	{
		/// fields

		/* settings : map < SettingId : size_t, Setting* > 
		Contains specific settings of class Setting. 
		All the settings regarding any specific topic should be added 
		in the Init() method. Here the Deserialize method will be 
		called to load the settings from the disk. 
		*/
		std::map<SettingId, Setting*> m_settings;

		/* settingsVersion : uint32_t 
		Version of settings to support several game versions. 
		ADVICE: make a static const var in the child class 
		of the SettingCollection that will hold the specific 
		settings version to avoid collision with other settings 
		specifications, i.e. 
				
				static const k_videoSettingsVersion = 1;
		*/
		uint32_t m_settingsVersion;

		/* settingsPath = string
		A path to a binary file where the settings a stored 
		on a disk. 
		NOTE: Here created not a stream to the settings file
		but only a file path, to file not be locked with the 
		app. 
		*/
		std::string m_settingsPath;

		DEBUG_(const std::string m_debugName);

	public:
		/// c'tor d'tor
		SettingCollection() = default;
		virtual ~SettingCollection() = default;

		SettingCollection(const std::string& filePath);
		DEBUG_(SettingCollection(const std::string& filePath, const std::string& settingsDbgName));

		/// Copy c'tor
		SettingCollection(const SettingCollection& rhs) = default;
		SettingCollection& operator=(const SettingCollection& rhs) = default;

		/// Move c'tor
		SettingCollection(SettingCollection&& rhs) = default;
		SettingCollection& operator=(SettingCollection&& rhs) = default;

		// Serialize/Deserialize (Load/Unload) methods
		virtual void Serialize(std::ostream& ostream) = 0;
		virtual void Deserialize(const std::istream& istream) = 0;

		// getters 
		Setting* operator[](SettingId settingId);
		Setting* get(SettingId settingId);

		uint32_t GetVersion() const;

	};

	//////////////////////////////////////////

	inline SettingCollection::SettingCollection(const std::string& filePath) 
		: m_settingsPath(filePath) {}

	inline SettingCollection::SettingCollection(const std::string& filePath, const std::string& settingsDbgName)
		: m_settingsPath(filePath), DEBUG_(m_debugName(settingsDbgName)) {}


	inline Setting* SettingCollection::operator[](SettingId settingId)
	{
		return get(settingId);
	}
	inline Setting* SettingCollection::get(SettingId settingId)
	{
		return m_settings[settingId];
	}

	inline uint32_t SettingCollection::GetVersion() const
	{
		return m_settingsVersion;
	}
}