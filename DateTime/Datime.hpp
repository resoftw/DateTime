#pragma once
#include <iostream>
#include <iomanip>
namespace Datime {
#define CEI constexpr inline	
#define CE constexpr
	
	enum class Hari {
		Ahad,Senin,Selasa,Rabu,Kamis,Jumat,Sabtu,
	};
	enum class Bulan {
		January=1,Februari,Maret,April,Mei,Juni,
		Juli,Agustus,September,Oktober,November,Desember,
	};

	class tahun {
		short t_;
	public:
		tahun() = default;
		CEI tahun(int y) noexcept : t_(static_cast<decltype(t_)>(y)) {}
		CEI tahun& operator++() noexcept { ++t_; return *this; }
		CEI tahun operator++(int) noexcept { auto tmp(*this); ++(*this); return tmp; }
		CEI tahun& operator--() noexcept { --t_; return *this; }
		CEI tahun operator--(int) noexcept { auto tmp(*this); --(*this); return tmp; }
		CEI tahun& operator+=(const tahun& t) noexcept { *this = *this + t; return *this; }
		CEI tahun& operator-=(const tahun& t) noexcept { *this = *this - t; return *this; }
		CEI operator int() const noexcept { return t_; }

		CEI bool kabisat() const noexcept {
			return t_ % 4 == 0 && (t_ % 100 != 0 || t_ % 400 == 0);
		}
	};
	CE tahun operator+(const tahun& x, const tahun& y) noexcept { return tahun{ static_cast<int>(x) + static_cast<int>(y) }; }
	CE tahun operator-(const tahun& x, const tahun& y) noexcept { return tahun{ static_cast<int>(x) - static_cast<int>(y) }; }

	class bulan {
		int b_;
	public:
		bulan() = default;
		CEI bulan(int b) noexcept :b_(static_cast<decltype(b_)>(b)) {}
		CEI bulan& operator++() noexcept { *this += bulan{1}; return *this; }
		CEI bulan operator++(int) noexcept { auto tmp(*this); ++(*this); return tmp; }
		CEI bulan& operator--() noexcept { *this -= bulan{1}; return *this; }
		CEI bulan operator--(int) noexcept { auto tmp(*this); --(*this); return tmp; }
		CEI bulan& operator+=(const bulan& b) noexcept { *this = *this + b; return *this; }
		CEI bulan& operator-=(const bulan& b) noexcept { *this = *this - b; return *this; }

		CEI operator int() const noexcept { return b_; }
	};

	CE bulan operator+(const bulan& x, const bulan& y) noexcept { return bulan{ static_cast<int>(x) + static_cast<int>(y) }; }
	CE bulan operator-(const bulan& x, const bulan& y) noexcept { return bulan{ static_cast<int>(x) - static_cast<int>(y) }; }

	class hari {
		int h_;
	public:
		hari() = default;
		CEI hari(int h) noexcept :h_(static_cast<decltype(h_)>(h)) {}
		CEI hari& operator++() noexcept { *this += hari{1}; return *this; }
		CEI hari operator++(int) noexcept { auto tmp(*this); ++(*this); return tmp; }
		CEI hari& operator--() noexcept { *this -= hari{1}; return *this; }
		CEI hari operator--(int) noexcept { auto tmp(*this); --(*this); return tmp; }
		CEI hari& operator+=(const hari& h) noexcept { *this = *this + h; return *this; }
		CEI hari& operator-=(const hari& h) noexcept { *this = *this - h; return *this; }

		CEI operator int() const noexcept { return h_; }
	};
	CE hari operator+(const hari& x, const hari& y) noexcept { return hari{ static_cast<int>(x) + static_cast<int>(y) }; }
	CE hari operator-(const hari& x, const hari& y) noexcept { return hari{ static_cast<int>(x) - static_cast<int>(y) }; }

	class jam {
		int j_;
	public:
		jam() = default;
		CEI jam(int j) noexcept :j_(static_cast<decltype(j_)>(j)) {}
		CEI jam& operator++() noexcept { *this += jam{1}; return *this; }
		CEI jam operator++(int) noexcept { auto tmp(*this); ++(*this); return tmp; }
		CEI jam& operator--() noexcept { *this -= jam{1}; return *this; }
		CEI jam operator--(int) noexcept { auto tmp(*this); --(*this); return tmp; }
		CEI jam& operator+=(const jam& j) noexcept { *this = *this + j; return *this; }
		CEI jam& operator-=(const jam& j) noexcept { *this = *this - j; return *this; }

		CEI operator int() const noexcept { return j_; }
	};
	CE jam operator+(const jam& x, const jam& y) noexcept { return jam{ static_cast<int>(x) + static_cast<int>(y) }; }
	CE jam operator-(const jam& x, const jam& y) noexcept { return jam{ static_cast<int>(x) - static_cast<int>(y) }; }

	class tanggal {
		tahun y_;
		bulan m_;
		hari d_;
	public:
		tanggal() = default;
		CEI tanggal(const tahun& y, const bulan& m, const hari& d) noexcept
			: y_(y),m_(m),d_(d) {}
		CEI tanggal& operator+=(const hari& h)noexcept {
			int d = d_;
			int n = h;
			int nd = d + n;
			int nm = dom();
			while (nd > nm) {
				nd -= nm;
				++m_;
				if (m_ == 13) {
					++y_;
					m_ = 1;
				}
				nm = dom();
			}
			while (nd < 1) {
				--m_;
				if (m_ == 0) {
					--y_;
					m_ = 12;
				}
				nd += dom();
			}
			d_ = nd;
			return *this;
		}
		CEI int dom(int y,int m) const noexcept {
			constexpr int dpm[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			tahun _y{ y };
			bulan _m{ m };
			return (_m == 2 && _y.kabisat()) ? 29 : dpm[int(_m) - 1];
		}
		CEI int dom() const noexcept {
			return dom(y_,m_);
		}
		friend std::ostream& operator<<(std::ostream& os, const tanggal& d) {
			os << d.y_ <<"/"<<std::setfill('0') << std::setw(2) <<d.m_<<"/"<< std::setfill('0') << std::setw(2)<<d.d_;
			return os;
		}
	};
	class waktu {
		int secs;
	public:
		waktu() = default;
		//CEI waktu(const )
	};

}

