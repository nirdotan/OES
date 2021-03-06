/* This software is available to you under a choice of one of two
* licenses.  You may choose to be licensed under the terms of the GNU
* General Public License (GPL) Version 2, available from the file
* COPYING, or the Open Ethernet BSD license below:
*
*     Redistribution and use in source and binary forms, with or
*     without modification, are permitted provided that the following
*     conditions are met:
*
*      - Redistributions of source code must retain the above
*        copyright notice, this list of conditions and the following
*        disclaimer.
*
*      - Redistributions in binary form must reproduce the above
*        copyright notice, this list of conditions and the following
*        disclaimer in the documentation and/or other materials
*        provided with the distribution.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
* BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
* ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
* CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE. 
*/

#ifndef __OES_API_ROUTER_H__
#define __OES_API_ROUTER_H__

#include <oes_types.h>

/************************************************
 *  API functions
 ***********************************************/

/**
 * This function sets the log verbosity level of router MODULE
 * @param[in]  verbosity_level  - router  module verbosity level
 *
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_router_log_verbosity_level_set(
                                      const int   verbosity_level
                                      );

/**
 * This function gets the log verbosity level of the router 
 * MODULE 
 * @param[out]  verbosity_level_p router  module verbosity level
 *
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_router_log_verbosity_level_get(
                                      int   * verbosity_level_p
                                      );



/**
 * This function sets the ECMP hash function configuration 
 * parameters. 
 *  
 * @param[in,out] vrid - Virtual router ID 
 * @param[in] ecmp_hash_params_p - ECMP hash configuration. 
 * @param[in,out] router_ecmp_hash_vs_ext- vendor specific 
 *       extension
 *
 * @return OES_STATUS_SUCCESS if operation completes successfully.
 * @return OES_STATUS_PARAM_NULL if parameter is NULL.
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e
oes_api_router_ecmp_hash_params_set(
                                   const unsigned int   vrid,
                                   const struct oes_router_ecmp_hash_fields * ecmp_hash_params_p,
                                   void * router_ecmp_hash_vs_ext
                                   );


/**
 * This function gets the ECMP hash function configuration 
 * parameters. 
 *  
 * @param[in,out] vrid - Virtual router ID 
 * @param[out] ecmp_hash_params_p - ECMP hash configuration. 
 * @param[in,out] router_ecmp_hash_vs_ext- vendor specific 
 *       extension
 *
 * @return OES_STATUS_SUCCESS if operation completes successfully.
 * @return OES_STATUS_PARAM_NULL if parameter is NULL.
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e
oes_api_router_ecmp_hash_params_get(
                                   const unsigned int   vrid,
                                   struct oes_router_ecmp_hash_fields * ecmp_hash_params_p,
                                   void * router_ecmp_hash_vs_ext
                                   );

/**
 *  This function adds/modifies/deletes a virtual router.
 *  The router ID is allocated and returned to the caller when
 *  cmd is ADD, otherwise it is given by the caller. All
 *  interfaces and routes associated with a router must be
 *  deleted before the router can be deleted as well.
 *  
 * @param[in] access_cmd - ADD/EDIT/DELETE. 
 * @param[in,out] vrid_p - Virtual router ID 
 * @param[in] router_attr_p - Router attributes. 
 * @param[in,out] router_vs_ext- vendor specific extension 
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if any input parameter is invalid. 
 * @return OES_STATUS_NO_RESOURCES if there are no resources to
 *         create another router
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e
oes_api_router_set(
                  const enum oes_access_cmd access_cmd,
                  unsigned int  * vrid_p,
                  const struct oes_router_attributes * router_attr_p,
                  void * router_vs_ext
                  );


/**
 *  This function gets a virtual router information.
 *  
 * @param[in] vrid - Virtual router ID
 * @param[out] router_attr_p - Router attributes. 
 * @param[in,out] router_vs_ext- vendor specific extension 
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if any input parameter is invalid. 
 * @return OES_STATUS_NO_RESOURCES if there are no resources to
 *         create another router
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e
oes_api_router_get(
                  const unsigned int   vrid,
                  struct oes_router_attributes * router_attr_p,
                  void * router_vs_ext
                  );


/**
 *  This function adds/modifies/deletes/delete_all a router
 *  interface. A router interface is associated with L2
 *  interface.
 * 
 * @param[in] access_cmd - ADD/EDIT/DELETE/DELETE ALL.
 * @param[in] vrid - Virtual Router ID. 
 * @param[in,out] rif_p - Router Interface ID.  
 * @param[in] ifc_p - Interface type and parameters e.g. 
 *       vlan,port ... 
 * @param[in] ifc_attr_p - Interface attributes e.g mac address 
 *       mtu ,rpc ... .
 * @param[in,out] router_interface_vs_ext- vendor specific 
 *       extension
 *
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if any input parameter is invalid.
 * @return OES_STATUS_ENTRY_NOT_FOUND if router interface was not added.
 * @return OES_STATUS_NO_RESOURCES if no interface is available to create. 
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e
oes_api_router_interface_set(
                            const enum oes_access_cmd access_cmd,
                            const unsigned int    vrid,
                            unsigned int * rif_p,
                            const struct oes_l3_interface * ifc_p,
                            const struct oes_l3_interface_attributes * ifc_attr_p,
                            void * router_interface_vs_ext
                            );

/**
 * This function gets a router interface information. 
 * 
 * @param[in] vrid - Virtual Router ID. 
 * @param[in] rif - Router Interface ID.  
 * @param[out] ifc - Interface type and parameters
 * @param[out] ifc_attr - Interface attributes 
 * @param[in,out] router_interface_vs_ext- vendor specific 
 *       extension
 *
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if any input parameter is invalid.
 * @return OES_STATUS_ENTRY_NOT_FOUND if router interface was not added. 
 * @return OES_STATUS_ERROR general error.
 */

oes_status_e
oes_api_router_interface_get(
                            const unsigned int   vrid,
                            const unsigned int  rif,
                            struct oes_l3_interface * ifc_p,
                            struct oes_l3_interface_attributes * ifc_attr_p,
                            void * router_interface_vs_ext
                            );

/**
 *  This function sets admin state of a router interface. Admin state is set per
 *  IP version.
 *
 * @param[in] vrid - Virtual Router ID.
 * @param[in] rif - Router Interface ID.
 * @param[in] admin_state_p - Admin state.
 * @param[in,out] router_interface_state_vs_ext- vendor specific
 *       extension
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if any input parameter is invalid.
 * @return OES_STATUS_ENTRY_NOT_FOUND if router interface was not added.
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e
oes_api_router_interface_state_set(
                                  const unsigned int   vrid,
                                  const unsigned int   rif,
                                  const struct oes_l3_interface_admin_state * admin_state_p,
                                  void * router_interface_state_vs_ext
                                  );



/**
 *  This function gets admin state of a router interface.
 *
 * @param[in] vrid - Virtual Router ID.
 * @param[in] rif - Router Interface ID.
 * @param[out] admin_state_p - Admin state.
 * @param[in,out] router_interface_state_vs_ext- vendor specific
 *       extension
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if any input parameter is invalid.
 * @return OES_STATUS_ENTRY_NOT_FOUND if router interface was not added.
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e
oes_api_router_interface_state_set(
                                  const unsigned int   vrid,
                                  const unsigned int   rif,
                                  struct oes_l3_interface_admin_state * admin_state_p,
                                  void * router_interface_state_vs_ext
                                  );


/**
 *  This function adds/deletes a MAC address from a router interface.
 * 
 * @param[in] access_cmd - ADD/DELETE/DELETE_ALL. 
 * @param[in] vrid - Virtual Router ID. 
 * @param[in] rif - Router Interface ID.
 * @param[in] mac_addr_list_p - MAC addresses array.
 * @param[in] mac_cnt - MAC addresses array size.
 * @param[in,out] router_interface_mac_vs_ext- vendor specific
 *       extension
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if any input parameter is invalid.
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e
oes_api_router_interface_mac_set(
                                const enum oes_access_cmd access_cmd,
                                const unsigned int   vrid,
                                const unsigned int   rif,
                                const struct ether_addr * mac_addr_list_p,
                                const unsigned short    mac_cnt,
                                void * router_interface_mac_vs_ext
                                );

/**
 *  This function gets MAC address of a router interface.
 * 
 * @param[in] access_cmd - ADD/DELETE/DELETE_ALL. 
 * @param[in] vrid - Virtual Router ID. 
 * @param[in] rif - Router Interface ID.
 * @param[out] mac_addr_list_p - MAC addresses array .
 * @param[in,out] mac_cnt_p - MAC addresses array size . 
 * @param[in,out] router_interface_mac_vs_ext- vendor specific
 *       extension 
 *
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if any input parameter is invalid.
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e
oes_api_router_interface_mac_get(
                                const enum oes_access_cmd access_cmd,
                                const unsigned int   vrid,
                                const unsigned int   rif,
                                struct ether_addr * mac_addr_list_p,
                                unsigned short  * mac_cnt_p,
                                void * router_interface_mac_vs_ext
                                );

/**
 *  This function adds/modifies/deletes/delete_all a neighbour
 *  information. The neighbour information associate an IP
 *  address to a MAC address. The neighbour IP addresses are
 *  learned via ARP/ND discovery at the control protocols layer,
 *  the interface that the neighbours are associated with is
 *  derived from the IP interface configuration. When calling
 *  with DELETE command, rif parameter is ignored. At DELETE_ALL
 *  operation the neighbours associated with the router
 *  interface parameter will be deleted in case it is valid, in
 *  case rif is invalid , all neighbours will be deleted.
 * 
 * @param[in] access_cmd - ADD/EDIT/DELETE/DELETE_ALL.
 * @param[in] vrid - Virtual Router ID. 
 * @param[in] neigh_key_p - neigh IP address. 
 * @param[in] neigh_data_p- neigh data including rif,mac address
 *       , action(TRAP/DROP/FORWARD) ,activity
 * @param[in,out] router_neigh_vs_ext- vendor specific extension
 *
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if any input parameter is invalid. 
 * @return OES_STATUS_NO_RESOURCES if no neighbour entry is available to create.
 * @return OES_STATUS_ERROR general error.
 */

oes_status_e 
oes_api_router_neigh_set(
                        const enum oes_access_cmd access_cmd,
                        const unsigned int   vrid,
                        const struct oes_ip_addr  * neigh_key_p,
                        const struct oes_neigh_data * neigh_data_p,
                        void * router_neigh_vs_ext
                        );

/**
 *  This function gets/get activity a neighbour information.
 *  function can receive four types of input: 
 *     1) get information for specific  neigh
 *      user should inserts  sepecific neigh as the first
 *      neigh_key element in the neigh_key array , neigh_cnt
 *      should be equal to 1, access_cmd should be
 *      OES_ACCESS_CMD_GET
 *  
 *     2) get neigh  activity information for specific neigh
 *      user should inserts sepecific neigh as the first
 *      neigh_key element in the neigh_key array , neigh_cnt
 *      should be equal to 1, access_cmd should be
 *      OES_ACCESS_CMD_GET_ACTIVITY
 *  
 *   - 3) get a list of first n neighs ,user
 *      should provide an empty  neigh_key array array
 *      neigh_cnt should be equal to n,access_cmd should be
 *      OES_ACCESS_CMD_GET_FIRST
 *
 *   - 4) get a list of n  neighs  which comes after
 *      certain neigh(it does not have to exist) user should
 *      insert the certain neigh as the first neigh_key element
 *      in the neigh_key array , neigh_cnt should be equal to n,
 *      OES_ACCESS_CMD_GET_NEXT
 * 
 * @param[in] access_cmd - GET/GET_NEXT/GET_FIRST/GET_ACTIVITY 
 * @param[in] vrid - Virtual Router ID.
 * @param[in,out] neigh_key_list_p - neigh IP address array 
 * @param[out] neigh_data_list_p- neigh data  array , each neigh
 *       data element includes rif,mac address ,
 *       action(TRAP/DROP/FORWARD) ,activity
 * @param[in,out] neigh_cnt_p - array size  
 * @param[in,out] router_neigh_vs_ext- vendor specific extension
 *
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if any input parameter is invalid.
 * @return OES_STATUS_ENTRY_NOT_FOUND if neighbour was not added.
 * @return OES_STATUS_ERROR general error.
 */

oes_status_e 
oes_api_router_neigh_get(
                        const enum oes_access_cmd access_cmd, 
                        const unsigned int   vrid,
                        struct oes_ip_addr  * neigh_key_list_p,
                        struct oes_neigh_data * neigh_data_list_p,
                        unsigned short  * neigh_cnt_p,
                        void * router_neigh_vs_ext
                        );

/**
 *  This function adds/deletes an unicast route into the routing
 *  table. The route is composed of network address and next hop
 *  array which may contains more than one entry for ECMP. In
 *  case the neigh, entry is not known yet,the route will be
 *  added with action TRAP . Upon neigh entry resolved and
 *  configured, the route can be modified into FORWARD. Calling
 *  with SET cmd will replace all next hop entries associated
 *  with the route. (If the route does not exist, it will be
 *  created).
 *  
 * @param[in] access_cmd - ADD/DELETE/DELETE ALL .
 * @param[in] vrid - Virtual Router ID.
 * @param[in] uc_route_key_p - IP network address+prefix len 
 * @param[in] uc_route_data_p - routing table data including 
 *       action(tarp,drop,forward),next-hop list
 * @param[in,out] router_uc_route_vs_ext- vendor specific 
 *       extension
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if any input parameter is invalid.
 * @return OES_STATUS_NO_RESOURCES if no routes is available to create.
 * @return OES_STATUS_ERROR general error.
 */

oes_status_e 
oes_api_router_uc_route_set(
                           const enum oes_access_cmd access_cmd, 
                           const unsigned int   vrid,
                           const struct oes_ip_prefix * uc_route_key_p,
                           const struct oes_uc_route_data * uc_route_data_p,
                           void * router_uc_route_vs_ext
                           );

/**
 * This function gets unicast route entires from the SDK The 
 * function can receive three types of input: 
 *     1) get information for specific  unicast route,user
 *      should insert the certain unicast route as the first
 *      uc_route_key element in the uc_route_key array ,
 *      uc_route_cnt should be equal to 1,
 *      access_cmd should be OES_ACCESS_CMD_GET
 *
 *   - 2) get a list of first n unicast routes ,user
 *      should provide an empty uc_route_key  array uc_route_cnt
 *      should be equal to n,access_cmd should be
 *      OES_ACCESS_CMD_GET_FIRST
 *
 *   - 3) get a list of n  unicast routes which comes after
 *      certain unicast route (it does not have to exist) user
 *      should insert the certain unicast route as the first
 *      uc_route_key element in the uc_route_key array ,
 *      uc_route_cnt should be equal to n,
 *      access_cmd should be OES_ACCESS_CMD_GET_NEXT
 *  
 * @param[in] access_cmd - GET/GET NEXT/GET FIRST.
 * @param[in] vrid - Virtual Router ID.
 * @param[in,out] uc_route_key_list_p  - IP network 
 *       address+prefix len array
 * @param[out] uc_route_data_list_p - routing table data 
 *       including action(tarp,drop,forward),next-hop list array
 * @param[in,out] uc_route_cnt_p - array size 
 * @param[in,out] router_uc_route_vs_ext- vendor specific 
 *       extension
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if any input parameter is invalid.
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e 
oes_api_router_uc_route_get(
                           const enum oes_access_cmd access_cmd, 
                           const unsigned int   vrid,
                           struct oes_ip_prefix * uc_route_key_list_p,
                           struct oes_uc_route_data * uc_route_data_list_p,
                           unsigned short * uc_route_cnt_p,
                           void * router_uc_route_vs_ext
                           );


/**
 *  This function allocates/deallocates a router interface
 *  counter.
 *
 * @param[in] access_cmd - ADD /DELETE . 
 * @param[in] vrid - Virtual Router ID. 
 * @param[in] rif - Router Interface ID.
 * @param[in,out] router_cntr_alloc_vs_ext- vendor specific 
 *       extension
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR f any input parameter is 
 *         invalid.
 * @return OES_STATUS_NO_RESOURCES if no counter is available to 
 *         create.
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e 
oes_api_router_interface_cntr_enable_set(
                                        const enum oes_access_cmd access_cmd, 
                                        const unsigned int   vrid, 
                                        const unsigned int   rif,
                                        void * router_interface_cntr_vs_ext
                                        );
/**
 * This function reads router interface counter 
 *
 * @param[in] access_cmd - READ/READ CLEAR. 
 * @param[in] vrid - Virtual Router ID. 
 * @param[in] rif - Router Interface ID. 
 * @param[out]cntr_p - Router Interface counter extension 
 * @param[in,out] router_cntr_alloc_vs_ext- vendor specific 
 *       extension
 *
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if any input parameter is invalid. 
 * @return OES_STATUS_ERROR general error.
 */

oes_status_e 
oes_api_router_interface_cntr_get(
                                 const enum oes_access_cmd access_cmd, 
                                 const unsigned int vrid,
                                 const unsigned int rif,
                                 struct oes_router_cntr * cntr_p,
                                 void * router_interface_cntr_vs_ext
                                 );


/**
*  This function adds/ deletes a multicast route into/from the
*  MC routing table.
* 
* @param[in] access_cmd - ADD/DELETE/DELETE_ALL
*       	   DELETE_ALL command deletes all multicast routes associated
*       	   with vrid.
* @param[in] vrid - Virtual Router ID.
* @param[in] mc_route_key_p - group ip, sender IP, ingress rif 
*       (in order to configure *.G rule sender IP should be
*       0.0.0.0)
* @param[in] mc_route_data_p -mc route action , egress rif list 
* @param[in,out] router_mc_route_vs_ext- vendor specific 
*       extension      
*
* @return OES_STATUS_SUCCESS if operation completes successfully. 
* @return OES_STATUS_PARAM_ERROR if any input parameter is invalid.
* @return OES_STATUS_NO_RESOURCES if no routes is available to create.
* @return OES_STATUS_ERROR general error.
*/

oes_status_e
oes_api_router_mc_route_set(
                           const enum oes_access_cmd access_cmd,
                           const unsigned int   vrid,
                           const struct oes_mc_route_key * mc_route_key_p,
                           const struct oes_mc_route_data * mc_route_data_p,
                           void * router_mc_route_vs_ext
                           );


/**
*  This function gets a multicast route from the MC routing table.
*  function can receive three types of input: 
 *     1) get information for specific multicast route,user
 *      should insert the certain multicast route as the first
 *      mc_route_key element in the mc_route_key array ,
 *      mc_route_cnt should be equal to 1,
 *      access_cmd should be OES_ACCESS_CMD_GET
 *
 *   - 2) get a list of first n multicast routes ,user
 *      should provide an empty mc_route_key  array mc_route_cnt
 *      should be equal to n,access_cmd should be
 *      OES_ACCESS_CMD_GET_FIRST
 *
 *   - 3) get a list of n  multicast routes which comes after
 *      certain multicast route (it does not have to exist) user
 *      should insert the certain multicast route as the first
 *      mc_route_key element in the mc_route_key array ,
 *      mc_route_cnt should be equal to n,
*       access_cmd should be OES_ACCESS_CMD_GET_NEXT
*  
* @param[in] access_cmd - GET/GET_NEXT/GET_FIRST/GET_ACTIVITY 
* @param[in] vrid - Virtual Router ID. 
* @param[in] mc_route_key_list_p  - array of mc_route_key each 
*       mc_route_key  element includes group IP, sender IP,
*       ingress rif (in order to configure
*       *.G rule sender IP should be 0.0.0.0)
* @param[out] mc_route_data_list_p  -array of mc_route_data 
*       each mc_route_data element includes mc route action ,
*       egress rif list
* @param[in,out] mc_route_cnt_p  - array size  
* @param[in,out] router_mc_route_vs_ext- vendor specific 
*       extension
*  
* @return OES_STATUS_SUCCESS if operation completes successfully.
* @return OES_STATUS_PARAM_ERORR if any input parameter is 
*         invalid.
* @return OES_STATUS_NOT_FOUND if mc route is not found
* @return OES_STATUS_ERROR general error.
*/

oes_status_e
oes_api_router_mc_route_get(
                           const enum oes_access_cmd access_cmd,
                           const unsigned int   vrid,
                           struct oes_mc_route_key * mc_route_key_list_p,
                           struct oes_mc_rout e_data * mc_route_data_list_p,
                           unsigned short  * mc_route_cnt_p,
                           void * router_mc_route_vs_ext
                           );


/**
*  This function adds/deletes an egress l3 interfaces to/from 
*  multicast route.
*
* @param[in] access_cmd - ADD/DELETE
* @param[in] vrid - Virtual Router ID. 
* @param[in] mc_route_key_p  -  mc_route_key  element includes 
*       group IP, sender IP, ingress rif (in order to configure
* @param[in] rif_list_p  -array of egress rif 
* @param[in] rif_cnt  -egress rif array size  
* @param[in,out] router_mc_egress_rif_vs_ext- vendor specific 
*       extension
*  
* @return OES_STATUS_SUCCESS if operation completes successfully. 
* @return OES_STATUS_PARAM_ERROR if any input parameter is invalid.
* @return OES_STATUS_NO_RESOURCES if no routes is available to create.
* @return OES_STATUS_ERROR general error.
*/
oes_status_e 
oes_api_router_mc_egress_rif_set(
                                const enum oes_access_cmd access_cmd,
                                const unsigned int  vrid,
                                const struct oes_mc_route_key * mc_route_key_p,
                                const unsigned int * rif_list_p,
                                const unsigned short rif_cnt,
                                void * router_mc_egress_rif_vs_ext
                                );


/**
*  This function get a list of  egress l3 interfaces from
*  multicast route. When egress_rif_num is 0 , the API will
*  return a counter of the number of egress rifs , and rif_list
*  will remain empty.
*  
* @param[in] vrid - Virtual Router ID. 
* @param[in] mc_route_key_p  -  mc_route_key  element includs 
*       group ip, sender IP, ingress rif (in oredr to configure
* @param[out] rif_list_p  -array of egress rif 
* @param[in,out] rif_cnt_p  -egress rif array size  
* @param[in,out] router_mc_egress_rif_vs_ext- vendor specific 
*       extension
*  
*
* @return OES_STATUS_SUCCESS if operation completes successfully.
* @return OES_STATUS_CMD_UNSUPPORTED if access command isn't supported.
* @return OES_STATUS_PARAM_EXCEEDS_RANGE if parameters exceed range.
* @return OES_STATUS_PARAM_ERROR if any input parameter is invalid.
* @return OES_STATUS_NO_RESOURCES if no routes is available to create.
* @return OES_STATUS_ERROR general error.
*/

oes_status_e 
oes_api_router_mc_egress_rif_get(
                                const unsigned int  vrid,
                                const struct oes_mc_route_key * mc_route_key_p,
                                unsigned int * rif_list_p,
                                unsigned short * rif_cnt_p,
                                void * router_mc_egress_rif_vs_ext
                                );


#endif /* __OES_API_ROUTER_H__ */
