// -----------------------------------------------------------------------------
// ISAVABLE
// -----------------------------------------------------------------------------

#pragma once

class Serializer;

namespace save
{
    class ISavable
    {
	public:
	virtual ~ISavable() {}

	public:
	virtual Serializer &	save(Serializer &) = 0;
	virtual Serializer &	load(Serializer &) = 0;
    };
}
