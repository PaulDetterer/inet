//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#ifndef __INET_TEMPORARYSHAREDPTRCLASS_H_
#define __INET_TEMPORARYSHAREDPTRCLASS_H_

#include "inet/common/Ptr.h"

namespace inet {

template<typename T>
class TemporarySharedPtr;

/**
 * This class provides support for Qtenv inspectors for objects referenced by shared pointers.
 */
template<typename T>
class TemporarySharedPtrClassDescriptor : public cClassDescriptor
{
  protected:
    cClassDescriptor *classDescriptor;

  protected:
    const Ptr<const T> getSharedPtr(void *object) const { return static_cast<TemporarySharedPtr<T> *>(object)->getObject(); }
    T *getObjectPointer(void *object) const { return const_cast<T *>(getSharedPtr(object).get()); }

  public:
    TemporarySharedPtrClassDescriptor(cClassDescriptor *classDescriptor) : cClassDescriptor(classDescriptor->getClassName()), classDescriptor(classDescriptor) { }

    virtual bool doesSupport(cObject *object) const override { return classDescriptor->doesSupport(getObjectPointer(object)); }
    virtual cClassDescriptor *getBaseClassDescriptor() const override { return classDescriptor->getBaseClassDescriptor(); }
    virtual const char **getPropertyNames() const override { return classDescriptor->getPropertyNames(); }
    virtual const char *getProperty(const char *propertyname) const override { return classDescriptor->getProperty(propertyname); }
    virtual int getFieldCount() const override { return classDescriptor->getFieldCount(); }
    virtual const char *getFieldName(int field) const override { return classDescriptor->getFieldName(field); }
    virtual int findField(const char *fieldName) const override { return classDescriptor->findField(fieldName); }
    virtual unsigned int getFieldTypeFlags(int field) const override { return classDescriptor->getFieldTypeFlags(field); }
    virtual const char *getFieldDeclaredOn(int field) const override { return classDescriptor->getFieldDeclaredOn(field); }
    virtual const char *getFieldTypeString(int field) const override { return classDescriptor->getFieldTypeString(field); }
    virtual const char **getFieldPropertyNames(int field) const override { return classDescriptor->getFieldPropertyNames(field); }
    virtual const char *getFieldProperty(int field, const char *propertyname) const override { return classDescriptor->getFieldProperty(field, propertyname); }
    virtual int getFieldArraySize(void *object, int field) const override { return classDescriptor->getFieldArraySize(getObjectPointer(object), field); }
#if OMNETPP_VERSION >= 0x0600
    virtual void setFieldArraySize(void *object, int field, int size) const override { classDescriptor->setFieldArraySize(getObjectPointer(object), field, size); }
#endif
    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override { return classDescriptor->getFieldDynamicTypeString(getObjectPointer(object), field, i); }
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override { return classDescriptor->getFieldValueAsString(getObjectPointer(object), field, i); }
#if OMNETPP_VERSION >= 0x0600
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override { classDescriptor->setFieldValueAsString(getObjectPointer(object), field, i, value); }
#else
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override { return classDescriptor->setFieldValueAsString(getObjectPointer(object), field, i, value); }
#endif
    virtual const char *getFieldStructName(int field) const override { return classDescriptor->getFieldStructName(field); }
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override { return classDescriptor->getFieldStructValuePointer(getObjectPointer(object), field, i); }
#if OMNETPP_VERSION >= 0x0600
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override { classDescriptor->setFieldStructValuePointer(getObjectPointer(object), field, i, ptr); }
#endif
};

/**
 * The only reason this class exists is to delete the proxy descriptors for the temporaryPtr objects
 * when a single static instance of it is deleted at process shutdown.
 * One destructor for each T is enough. - Perhaps this map _always_ contains _exactly_ one element...? So could be removed?
 */
template <typename T>
struct TemporarySharedPtrClassDescriptorRegistry {
    std::map<cClassDescriptor *, TemporarySharedPtrClassDescriptor<T> *> proxyDescs;

    TemporarySharedPtrClassDescriptor<T> *getOrCreateProxyDescriptorFor(cClassDescriptor *origDesc) {
        if (proxyDescs.find(origDesc) == proxyDescs.end())
            proxyDescs[origDesc] = new TemporarySharedPtrClassDescriptor<T>(origDesc);
        return proxyDescs[origDesc];
  }
    ~TemporarySharedPtrClassDescriptorRegistry() {
        for (auto a : proxyDescs)
            delete a.second;
    }
};

/**
 * This class provides support for Qtenv inspectors for objects referenced by shared pointers.
 */

template<typename T>
class TemporarySharedPtr
#if OMNETPP_BUILDNUM >= 1502
    : public cTemporary
#else
    : public cObject // in this case, these objects will leak :(
#endif
{
  private:
    static TemporarySharedPtrClassDescriptorRegistry<T> proxyDescriptorRegistry; // we only need to create one instance for every T in Ptr<T>

    const Ptr<const T> object;
    TemporarySharedPtrClassDescriptor<T> *classDescriptor = nullptr;

  public:
    TemporarySharedPtr(const Ptr<const T> object) : object(object),
        classDescriptor(proxyDescriptorRegistry.getOrCreateProxyDescriptorFor(object.get()->getDescriptor())) { }
    virtual ~TemporarySharedPtr() {  }

    const Ptr<const T>& getObject() const { return object; }
    virtual cClassDescriptor *getDescriptor() const override { return classDescriptor; }
};

template<typename T>
TemporarySharedPtrClassDescriptorRegistry<T> TemporarySharedPtr<T>::proxyDescriptorRegistry;

} // namespace

#endif // #ifndef __INET_TEMPORARYSHAREDPTRCLASS_H_

