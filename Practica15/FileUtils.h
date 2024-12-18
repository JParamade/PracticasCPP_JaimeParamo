#pragma once

class CStream {
public:
	virtual void Open() = 0;
	virtual void Close() = 0;
	virtual void Read() = 0;
	virtual void Write(const char* data) = 0;
};

class CFile : public CStream {
public:
	virtual void Open() override;
	virtual void Close() override;
	virtual void Read() override;
	virtual void Write(const char* data) override;
};

class CCom : public CStream {
	virtual void Open() override;
	virtual void Close() override;
	virtual void Read() override;
	virtual void Write(const char* data) override;
};

class CTcp : public CStream {
	virtual void Open() override;
	virtual void Close() override;
	virtual void Read() override;
	virtual void Write(const char* data) override;
};