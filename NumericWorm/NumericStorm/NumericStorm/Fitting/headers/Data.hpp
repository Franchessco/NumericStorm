#pragma once
#include <memory>
#include <vector>

namespace NumericStorm 
{

template <typename T_v>
class Data 
{
using const_v = const std::vector<T_v>;
using v_shared = std::shared_ptr < std::vector<T_v>>;
using const_v_shared = std::shared_ptr<const_v>;

public:
	/*int i = 0;
	template<class ... Args>
	Data(Args... args)
	{

		struct zip 
		{
			std::map<int, std::vector<T_v>> myIterator;
			zip(Args... args)
			{
				int i = 0;
				for (auto d : args...)
					myIterator.emplace(i++, d);
			}

		};
		
		for (auto&& [i,item] : zip(args...).myIterator)
			m_vectorPointers[i] = std::make_shared<const_v_shared>(item);
		

		for (int i =0;i<sizeof...(Args);i++)
		{
			m_data[i] =  args[i];
			m_vectorPointers[i] = std::make_shared<const_v_shared>(m_data[i]);
		}
	}
		*/
	template <class... Args>
	Data(Args... args) : m_data{ args... }{
		m_vectorPointers.resize(m_data.size());
		int i = 0;
		for (auto&& vec : m_data) {
			m_vectorPointers[i] = std::make_shared<const_v>(vec); i++;
		}
	}
	std::vector<std::vector<T_v>> getData() { return m_data; }
private:
	const std::vector<std::vector<T_v>> m_data;
	std::vector<const_v_shared> m_vectorPointers;

};

}
