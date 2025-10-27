/**
 * @file APIDto.h
 * @brief Define Data Transfer Objects to serialize/deserialize objects in requests
 * @author Gerard Jordaan
 * @note Inspiration taken from https://github.com/oatpp/oatpp-starter/blob/master/src/dto/DTOs.hpp
 */
#ifndef DTOS
#define DTOS

#include "oatpp/macro/codegen.hpp"
#include "oatpp/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * @class MyDto
 * @brief Data Transfer Object. Object containing fields only.
 *  Used in API for serialization/deserialization and validation
 */
class APIDto : public oatpp::DTO {
  
  DTO_INIT(APIDto, DTO)
  
  DTO_FIELD(Int32, statusCode); // HTTP status code
  DTO_FIELD(String, message); // JSON message
  
};

/**
 * @class BuyPlantDTO
 * @brief Data Transfer Object for buying plants request
 * Uses POST request body instead of query parameters for security
 */
class BuyPlantDTO : public oatpp::DTO 
{
  DTO_INIT(BuyPlantDTO, DTO)
  
  DTO_FIELD(String, plant);    // Plant variety to buy
  DTO_FIELD(Int32, numToBuy);  // Number of plants to buy
  
};

/**
 * @class AddCustomersDTO
 * @brief Data Transfer Object for adding customers request
 */
class AddCustomerDTO : public oatpp::DTO 
{
  DTO_INIT(AddCustomerDTO, DTO)
  
  DTO_FIELD(String, customerType);  // Customer type to add
  DTO_FIELD(Int32, numToAdd);       // Number of customers to add
};

#include OATPP_CODEGEN_END(DTO)

#endif // DTOS