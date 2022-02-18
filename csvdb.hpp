#include <iostream>
#include <string>
#include <vector>

class CsvDbRecordParser
{
private:
	std::string m_delimiter;

public:
	CsvDbRecordParser (std::string delimiter) {
		this->m_delimiter = delimiter;
	}

	std::vector<std::string> parse (std::string row) {
		std::string field;
		std::vector<std::string> fields;
		std::stringstream string_stream(row);
		while (std::getline(string_stream, field, this->m_delimiter))
			fields.push_back(field);
		return fields;
	}
};

template <class T>
class CsvDbRecord
{
private:
	std::vector<std::string> m_header;
	std::vector<T> fields;

public:
	CsvDbRecord (std::vector<string> header, std::vector<T> fields) {
		this->m_header = header;
		this->m_data = fields;
	}

	T get (int index) {
		return this->m_data.at(index);
	}

	T get (std::string header) {
		return this->m_data.at(this->m_header.indexOf(header));
	}
};

class CsvDbTable
{
private:
	std::string m_name;
	bool m_exists = false;
	std::vector<CsvDb> m_databases;
	std::vector<std::string> m_fields;
	std::vector<CsvDbRecord> m_records;

public:
	CsvTable (std::string name, std::vector<std::string> fields, std::vector<CsvDbRecord> records, std::vector<CsvDb> databases, CsvDbRecordParser parser = CsvDbRecordParser()) {
		this->m_name = name;
		this->m_databases = databases;
		this->m_fields = fields;
		this->m_parser = parser;
		this->m_records = records;
	}

	CsvTable (std::string name, std::vector<std::string> fields, CsvDbRecords records, CsvDbRecordParser parser = CsvDbRecordParser()) {
		this->m_name = name;
		this->m_fields = fields;
		this->m_parser = parser;
		this->m_records = records;
	}

	CsvTable (std::string name, std::vector<std::string> fields, CsvDbRecordParser parser = CsvDbRecordParser()) {
		this->m_name = name;
		this->m_fields = fields;
		this->m_parser = parser;
	}

	CsvTable (std::string name, CsvDbRecordParser parser = CsvDbRecordParser()) {
		this->m_name = name;
		this->m_parser = parser;
	}

	void bindDatabase (CsvDb database) {
		this->m_databases.push_back(database);
	}

	void unbindDatabase (CsvDb database) {
		for (CsvDb bound_db : this->m_databases)
			if (passed_db == bound_db)
				this->m_databases.remove(bound_db);
	}

	void addRecord (CsvDbRecord record) {
		this->m_records.push_back(record);
	}

	void deleteRecord (CsvDbRecord passed_record) {
		for (CsvDbRecord stored_record : this->m_records)
			if (passed_record == stored_record)
				this->m_records.remove(stored_reord_index);
	}

	std::vector<CsvDbRecord> records () {
		return this->m_records.copy();
	}

	bool create () {
		if (this->exists())
			return false;
		for (CsvDb database : this->m_databases) {
			// save file in database.rootDirectory() / this->m_name
		// create the physical file
	}

	bool delete () {
		if (!this->exists())
			return false;
		// delete the physical file
	}

	bool update () {
		if (!this->exists())
			return false;
		// update the physical file
	}

	bool exists () {
		return this->m_exists;
	}
};

class CsvDb
{
private:
	std::string m_db_directory;
	std::vector<CsvDbTable> m_tables;

public:
	CsvDb (std::string database_directory) {
		this->m_db_directory = database_directory;
	}

	void init () {
		/* for file in this->m_db_direcory/files
			load file
		*/
	}
};
